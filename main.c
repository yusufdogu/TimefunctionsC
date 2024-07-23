#include <stdio.h>
#include <time.h>
#include <unistd.h>
void timet();
void ctime_t();
void gm_time_t();
void strftime_t();
void mktime_t();
int main(void) {
    timet();
    ctime_t();
    gm_time_t();
    strftime_t();
    mktime_t();
}
void timet() {
    time_t start,end;
    start=time(NULL);//using 0 instead of NULL also valid
    sleep(2);
    end=time(0);
    printf("%.0f",difftime(end,start));

}
void ctime_t() {
    time_t curr_time=time(NULL);
    char *t_string=ctime(&curr_time);
    printf("%s",t_string);

}
void gm_time_t() {
    time_t curr_time=time(NULL);
    struct tm *gm_time=gmtime(&curr_time),*local=localtime(&curr_time);
    printf("%d",gm_time->tm_hour);
    printf("UTC: %s", asctime(gm_time));
    printf("Local: %s", asctime(local));
}
void strftime_t() {
    char tbuff[80];
    time_t curr_time=time(NULL);
    struct tm *local=localtime(&curr_time);
    strftime(tbuff,sizeof(tbuff),"%Y-%m-%d %H:%M:%S",local);
    printf("%s",tbuff);
}
void mktime_t() {
    time_t curr=time(NULL);
    struct tm *time=localtime(&curr);
    time_t time_sec;
    time_sec=mktime(time);
    printf("%lld",time_sec);
}