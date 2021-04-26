/*-------------------------------------------------------------
** �ļ���: zhengting.c
** Copyright (c) 2000-2001
** ������: ��ݹ�����
** ��  ��: 2001/08/13
** ��  ��: �������
**-----------------------------------------------------------*/

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","�������");

        set("long","��������ݵ����������Ϸ�����һ����������ĸ�����"+HIY"���侫��"NOR+"����
�й���һ����(hua)��һ������(duilian)����������˼������Ρ��ڻ���
�����һ��Сľ��(door)����ͨ����ɽ�ġ�
");
        set("no_steal", 1);
        set("valid_startroom",1);

         set("exits",([ 
                "east" : __DIR__"zoulang1",
                "west" : __DIR__"zoulang2",
                "south" : __DIR__"yanwuting2", 
                 ]));
         
         set("item_desc", ([
                "hua" : "�˻������������е�һλ������������λ�������Ǵ���ݵĴ����ˡ�\n",
		"door" : "һ��Сľ�ţ�����Դ�(open)����\n",
                "duilian" : "
   	         ��������     ��������
		 ��"+HIC" ܱ "NOR+"��     ��"+HIC" �� "NOR+"��
		 ��"+HIC" �� "NOR+"��     ��"+HIC" �� "NOR+"��
		 ��"+HIC" �� "NOR+"��     ��"+HIC" �� "NOR+"��
		 ��"+HIC" �� "NOR+"��     ��"+HIC" ͼ "NOR+"��
		 ��"+HIC" �� "NOR+"��     ��"+HIC" �� "NOR+"��
		 ��"+HIC"    "NOR+"��     ��"+HIC"    "NOR+"��
		 ��"+HIC" �� "NOR+"��     ��"+HIC" �� "NOR+"��
                 ��"+HIC" �� "NOR+"��     ��"+HIC" �� "NOR+"��
		 ��"+HIC" �� "NOR+"��     ��"+HIC" �� "NOR+"��
		 ��"+HIC" ֪ "NOR+"��     ��"+HIC" Ŭ "NOR+"��
		 ��"+HIC" �� "NOR+"��     ��"+HIC" �� "NOR+"��	
		 ��������     ��������\n",
          ]));

	set("objects", ([
		__DIR__"npc/mawude" : 1,
	]));

//	create_door("north", "ľ��", "south", DOOR_CLOSED);
	"/clone/board/wuguan_b"->foo();

        set("cost",1);

     setup();
}

void init()
{
   object me = this_player();

   if ( interactive(me) && me->query("wuguan/job_pending") ) {
	me->set_temp("wuguan_job/zt", 1);
   }
   
	  add_action("do_open", "open");
	  add_action("do_close", "close");     
}

void close_door()
{
        object room;

        if(!( room = find_object(__DIR__"xiaojing1")) )
                room = load_object(__DIR__"xiaojing1");
        if(objectp(room))
        {
                delete("exits/north");
		message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", this_object());
                room->delete("exits/south");
                message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", room);
        }
}

int do_close(string arg)
{
	 object room;
        if (!query("exits/north"))
                return notify_fail("ľ���Ѿ��ǹ��ŵ��ˡ�\n");

        if (!arg || (arg != "door" && arg != "north" && arg != "men"))
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object(__DIR__"xiaojing1")) )
                room = load_object(__DIR__"xiaojing1");
	delete("exits/north");
	message_vision("$N�����Сľ�Ź����ˡ�\n", this_player());
        room->delete("exits/south");
        message("vision", "�������˰�ľ�Ź����ˡ�\n", room);
        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/north"))
                return notify_fail("ľ���Ѿ��ǿ����ˡ�\n");

        if (!arg || (arg != "door" && arg != "north" && arg != "men"))
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object(__DIR__"xiaojing1")) )
                room = load_object(__DIR__"xiaojing1");
        if(objectp(room))
        {
                set("exits/north", __DIR__"xiaojing1");
                message_vision("$N����ذ�ľ�Ŵ򿪡�\n", this_player());
                room->set("exits/south", __FILE__);
                message("vision", "֨��һ�����������˰�ľ�Ŵ��ˡ�\n", room);
                remove_call_out("close_door");
                call_out("close_door", 40);
        }

        return 1;
}
/*int valid_leave(object me, string dir) 
{ 
	object *inv; 
	int i; 
	inv = all_inventory(me); 

        if ((dir == "south" || dir == "north" || dir == "west") 
             && !(int)me->query_temp("mark/��") && !wizardp(me) )
		return notify_fail("����ºȵ�������������������Ҵ���\n"); 
	return ::valid_leave(me, dir); 
}             
//*///ir); 
//}             
