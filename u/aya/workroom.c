// workroom.c ����Ʈ��� 
//by aya 4 2002 
#include <ansi.h>; 
inherit ROOM; 

void create()  
{
        set("short", "����Ʈ���"); 
        set("long", @LONG
  ������ʦ��櫵�ס����������ű��£�һ����������ܸо�  
  �������㣬��̨�Ϸ���һ�������ϲ����ˮ�ɻ�(hua)������
  ���Ϸ�����һ����(windbell),һ��紵�������巢���������� 
  ���������������������������£��������������ص��������
  ���Ե�����ȥ�ĵط���  
LONG
        );

        set("exits", ([ 
                "out":"/d/wizard/wizard_room",
                "gm":"/d/gumu/houtang", 
                "sl":"/d/shaolin/guangchang1", 
        ])); 

        set("item_desc", ([  
                "hua" : "һ�躬�����ŵ�ˮ�ɣ�������������\n",  
                "windbell" : "һ�����������ķ��壬�ǳ�Ư����\n", 
        ]));  

        set("objects", ([  
                __DIR__"npc/ya" : 1,   
                __DIR__"obj/ziqing.c" : 1,   
        ])); 

        set("sleep_room",1); 
        set("no_fight",1);
        set("no_steal",1);
        setup();
}
