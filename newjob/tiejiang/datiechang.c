#include <ansi.h> 
         
inherit ROOM; 
        
void create() 
       
{ 
set("short", HIC"������"NOR); 
 set("long", @LONG 
����һ���ľ߹�ģ�Ĵ����������Ͻ�����һ��ˮ�أ������������������ר 
�õĴ����ң���ʱ�������������Ľ���ײ���������������ٽ�һ�Ҵ����̵ĺ��� 
�������ķ���ͨ����ֵ�·�ܿ������������������У�Ҳ�����Ե�ӵ������ 
����ͣ�ż����⳵����Щ�������Ƕ�æ��װжһ�˴�����ԭ�Ϻͳ�Ʒ�� 
LONG 
); 
       
                      set("no_fight", "1");  
       
              set("exits", ([ 
                    "east" : "/newjob/tiejiang/datiefang1.c", 
                   "west" : "/newjob/tiejiang/datiefang2.c", 
                    "south" : "/newjob/tiejiang/datiefang3.c", 
                    "down" : "/newjob/tiejiang/datiefang4.c", 
                    "north": "/d/city/datiepu", 
                    "northwest" : "/d/city/dongdajie1", 
       
                       ])); 
       
              set("objects", ([ 
                          __DIR__"npc/bai" : 1, 
                              ]) ); //Newbe add 
       
              setup(); 
			          call_other("/clone/board/tiejiang_b", "???");

      } 
      //Newbe add 
    int valid_leave(object me, string dir) 
    {  
            if (dir == "south" && !me->query_temp("datiechang/enter") || dir == "west" && !me->query_temp("datiechang/enter")  
            || dir == "east" && !me->query_temp("datiechang/enter") || dir == "down" && !me->query_temp("datiechang/enter")) 
            return notify_fail("�㻹û�õ�����ͬ���ء�\n"); 
            return 1; 
    } 
       
       
