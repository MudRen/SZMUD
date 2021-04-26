// Code of ShenZhou
// Room: /city/xidajie2.c
// YZC 1995/12/04 
// mariner 2002 added cloth check
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�����");
    set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�����ϡ
�٣������ĵغ������塣������������Է���в��ٷ���֮ʿ�ۼ������������
��Ӫ�����ϱ߾��������ˡ�
LONG );
    set("outdoors", "city");
    set("no_clean_up", 0);
  set("fanhua",2);
    set("exits", ([
            "east"  : __DIR__"xidajie1",
            "north" : __DIR__"bingyindamen",
            "west"  : __DIR__"xidajie3",
            "south" : __DIR__"yamen",
    ]));

    setup();
    replace_program(ROOM);
}

void init()
{
    object me = this_player();
    object *inv, chk, bott, curtea;
	
    int i, nocloth = 1;
    inv = all_inventory(me); 
    for(i=0; i<sizeof(inv); i++) 
    {
       if( inv[i]->query("equipped") && inv[i]->query("armor_type")=="cloth" ) 
       {
            nocloth = 0; 
            break;
        }
    }
    if ( nocloth )
    {
        me->set( "no_cloth", 1 );
		message_vision(HIY"���컯�գ����ҵ����㱼����\n\n"NOR, me);
        me->move( __DIR__"dalao" );
		message_vision(RED"ֻ����������һ�����㱻�ٸ�����Ͷ���˴���������\n\n"NOR, me);
        command ("chat "+this_player()->query("name")+"��Ͷ�����ݴ�����");
		message_vision("һ���������߹������Ӹ���һ������ͷ��\n",me);
      	
		chk = new(__DIR__"jilei");
		chk->move(environment(me));

		if (objectp(curtea = present("wan", environment(me))))
        {       message_vision("������ѿ�����ʣ�裬һ��û��ת�����ˡ�\n", me);
                destruct(curtea);
        }
        else
                message_vision("�����䵹����ˮ���ڵ��ϡ�\n", me);

        bott = new("d/wudang/obj/dawancha");
        bott->move( environment(me));

	}   
}
