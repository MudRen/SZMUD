// chemahang.c ���ݳ�����   
// snowlf by 2001.11.14
//troy by 2001.12.13
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIW+"���ݳ�������"NOR);
        set("long", HIW+"
                      �����ݳ����С�"+NOR+"���
                         
    ���ݳ����������ݡ�����ȸ�����ж����˷ֺš������е�Ļ
���ϰ��˵��Ϧ��һλ���ƽ���������ǰ����������������������
����Ƕ��������������˳����У���Ӫ���೵�����⣬��ҵ�񣬷�
�����������á�
");

        
        set("exits", ([

                "south" : "/d/city/kedian",
                "enter":"/d/city/majiu",
                "southeast" : "/d/city/beidajie1",
        ]));

       set("out_door","city");
       set("valid_startroom",1);
        set("no_clean_up",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_get",1);

        set("objects",([
               __DIR__"npc/cmh_huoji":1,
               
    	   ]));     
        setup();

}
