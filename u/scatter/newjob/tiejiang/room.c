//code by cheap
//11/10/01/
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short",HIC"�ӻ���"NOR);
        set("long",
"�����ǳ���ո��¿��ŵ��ӻ��̣�һ�顰������ƽ���Ĵ��Ҹ߹���Լ��߸�\n" 
"�Ĺ�̨�Ϸ����Աߵ�һЩ������ʿ�������ĺ��ϰ��������������۸��ϰ���΢\n" 
"Ц�Ĵ������㣬�ڵ�Ķ�������һ������(paizi)��\n " 
           ); 

        set("exits", ([ 
            "east":"/newjob/tiejiang/gate1",
                      ])); 

       set("item_desc", ([ 
            "paizi" : "�������������Ʒ:
     ��(Gao)             ����������
     ��ǥ(Qian)          ����������
     ������(Da tie chui) ��һ������\n" ,
                         ]));
        set("objects", ([ 
            "/newjob/tiejiang/npc/tian.c" : 1,   ]) );
        set("day_shop",1);
        set("no_clean_up",0);
        setup();
}

