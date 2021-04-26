// Code of ShenZhou
// Room: /d/murong/boat1
//arthurgu 1999.9

#include <ansi.h>
inherit ROOM;

void init();
int do_jump(string);
int do_bow(string);

void create()
{
	set("short", "С��");
	set("long", @LONG
  С����������ӵ��±ߣ��밶(bank)��Զ�����������˾��İ�
�źõ��������ߡ���Ϊ��С���������ɶ����ˡ������ڷ���һ��
��(jiang)��
LONG
 );

	set("cost", 1);
	set("outdoors", "murong");
        
         set("item_desc", ([
              "bank" :
"����Զ�������������(jump)��ȥ��",
              "jiang" :
"һ��С�����ǻ�(row)���õġ�",
                           ]));
 
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_row", "row");
}
 
int do_jump(string arg)
{
	object me;
        me = this_player() ;

	if (!arg || (arg != "bank" ))
	{
		return notify_fail("�����Ķ�����\n");	
	}
	
	me->move("/d/murong/road1");
        message_vision("$N�Ӵ������˹�������ɫ�е�԰ס�\n",me);
        
        return 1 ;
}

int do_row(string arg)
{    object me;
     me = this_player() ;

     if (!arg )
	{
		return notify_fail("���������˼��£�С�����Ŵ�ת��������Ҫ��Ҫ��׼һ������\n");	
	}

    if (arg != "mantuo" 
    && arg != "shenhe"
    && arg != "tingxiang")
       return notify_fail("û��������� \n");
    

     me->move("/d/murong/hu");
     return 1 ;
}