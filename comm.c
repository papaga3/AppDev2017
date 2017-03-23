#include "comm.h"
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
void send_data_curl(double Leq[])
{
	char postdata[200]="data=", temp[30];
	CURL *curl;
 	CURLcode res;
	int i;
	for(i=0;i<8;i++)//this is for liip propare for the post string
	{
		sprintf(temp, (i==7)?"%.2f":"%.2f;", Leq[i]);
		strcat(postdata, temp); //append temp to postdata      
	}
	//post data is ready

   	curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        if(curl)
        {
		//printf("postdata = %s\n", postdata);
                curl_easy_setopt(curl, CURLOPT_URL, URL);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);
                res = curl_easy_perform(curl);
                if(res != CURLE_OK)
                {
                        fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
                }
                curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
}
