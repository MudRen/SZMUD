//Cracked by Kafei
#include "room.h"

inherit ROOM;

int valid_leave();


void create()
{
        set("short", "�����´���");
        set("long", @LONG
�����ɰ����ģ��������졣�������ּ�С����ֻ��������
�񾲡� ǰ���������������ڵ�·���ԣ�·�ľ�ͷ��һ�¸߸�
��שǽ��������һ����ľ�ţ�����һ�����(bian)��
LONG
        );


        set("outdoors", "dali");
          set("item_desc", ([
                "bian" : 			
"       \n"
"�����������������աաաաաաաաաաաաաաաա�\n"
"�����������������աա��������������������������ա�\n"
"�����������������աա�  ����   ��   ��        �ա�\n"
"�����������������աա��������������������������ա�\n"
"�����������������աաաաաաաաաաաաաաաա�\n"
        ]));


        set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"tianls2.c",
  "southdown" : __DIR__"hongshengt.c",
]));
        
         set("cost", 2);
        setup();  
}
void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me = this_player();
if ( me->query("family/master_id") == "kurong dashi")   


{
write ("׳��ɮ�˲����ÿ���˵����ʦ�������ˣ������\n");
me->move("/d/dali/tianls13.c");
}
if ( me->query( "family/master_name") != "���ٴ�ʦ" )
{
write("�ź���������׳��ɮ�ˣ���������ǰ˵������λ" + 
RANK_D->query_respect(this_player()) 
+"���������ڸ�ɮ�������ˣ�������ذɡ�\n");
}
return 1;
}

 