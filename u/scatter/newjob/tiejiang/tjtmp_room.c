// tjtmp_room.c ��Ʒ������������  �˫~�K�K�u�@����  
// snowlf by 2001.10.24
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short","��Ʒ"+HIB+"������������"NOR);
        set("long","�����Ƕ�ְҵϵͳ��һ��������Ʒ"+HIB+"������������"+NOR+"������һ����ɽ��ˮ
��Сɽ���£���ǰ�ոս��õ�ʱ�򣬻�ֻ��һ��տյķ��ӣ�����ʲôҲ
û�У��������ڵ�һ�����Ա�Ѿ����˲��ٶ����Ž����ˣ�
");

        
        set("exits", ([

		"out" : "/d/quanzhou/datiepu",

        ]));


/*
      	set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",1);
*/
        set("objects",([
               __DIR__"npc/tjtmp_npc":1,
               __DIR__"obj/datiechui":1,
               __DIR__"obj/gangqian":1,
               __DIR__"obj/gao":1,
               
    	   ]));     
        setup();

}
