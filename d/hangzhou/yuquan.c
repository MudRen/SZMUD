// Code of ShenZhou
// ��Ȫ
// Dong  11/03/1996.
// modified by aln  2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "��Ȫ");
   set("long", @LONG
��Ȫ�½�����Ȫɽ�ϣ�ԭ�������¡��߽���Ȫ�£�ֻ�������м���ˮ��(pond)��
�������ǳ�����ɽ��·��
LONG
        );

   set("exits", ([ /* sizeof() == 1 */ 
                  "eastdown" : __DIR__"road15", 
                  "west" : __DIR__"shuyuan",
                ])
       );
	set("objects", ([
                "/d/huashan/npc/youke" : 1,
        ]));
       
	set("cost", 2);
        set("outdoors", "hangzhou");
   setup();
}

void init()
{
   add_action("do_look","look");
   add_action("do_fishing","��");
   add_action("do_fishing","fishing");
   add_action("do_fishing","����");

}
int do_look(string arg)
{  
   if( !arg || arg=="" ) return 0;
   if( arg=="pond" )
   {   switch (random(3)) {
   	 case 0:
   		write("���Ե�ʯ�����š����ֹ������������˰�����ʮ���صĴ���(fish)��\n");
		write("����������£��ο��Ƿ׷�Ͷ��ι�㡣\n");
		break;
	 case 1:
   		write("���Ե�ʯ�����š�������Ȫ��������ż��Сˮ����ӿ������һ������\n");
		break;
	 case 2:
   		write("���Ե�ʯ�����š����ϸ��ء������������ڳ�ˮ�ϣ�����ȥ������\n");
		write("��ϸ�ꡣ\n");
		break;
	return 1;
   }
   if( arg=="fish" )
   {	int f;
	f = (int)((int)this_player()->query("food") / (int)this_player()->max_food_capacity() * 100);
	if (f > 50)
	{   write("����һ�������㣬����������������ȥ����ɰ���\n");
	}
	else
	{   message_vision("$N����һ�������㣬��ͣ�����ſ�Ҫ�������Ŀ�ˮ\n", this_player());
	}
   }
   return 1;
}
}
int do_fishing()
{  message_vision("$N�Ӵ����ͳ�һ����ͣ����οͲ�����۹��¿�ʼ���㡣����\n", this_player());
   message_vision("�ۣ���һ���һ����������Ϲ��ˡ�$N�˸߲��ҵ�ץ���㣬�ο���\n", this_player());
   message_vision("ȴ����ŭ����$N������Ŀ����֮��$Nֻ�û�����İ���Żس��С�\n", this_player());
   return 1;
}
