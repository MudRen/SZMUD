// Code of ShenZhou
// wsky, 5/7/00
inherit ROOM;

#include <ansi.h>
#include "/d/REGIONS.h";
#include "xx_job.h";

void setup_npc(object me, object ob);

void create()
{
        set("short", "��������");
        set("long", @LONG
���������޺��Աߵ�ɭ�֣��ߴ���������������еĹ��߶�����ס�ˡ�
���ϵ������ǲ�֦��Ҷ��ÿ̤��һ�����ᷢ��֨֨�����죬Զ����ʱ��
��һ����������ʹ��ë���Ȼ��
LONG);

        set("exits", ([ 	
             "north" : __DIR__"forest2",
	     "northwest" : __DIR__"forest3",
             "northeast" : __DIR__"forest4",   
	     "south" : __DIR__"xxh5",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "xingxiuhai");

        set("cost", 2);
        setup();
        

}


