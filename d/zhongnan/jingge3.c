// Code of ShenZhou
// road: /zhongnan/jingge3.c
// sdong 08/05/98 �ؾ�����¥

#include <ansi.h>
inherit ROOM;

string* books = ({
		  "laozi1",
		  "daodejing-i",
		  "laozi2",
		  "daodejing-i",
		  "laozi8",
		  "daodejing-i",
		  "laozi13",
		  "laozi1",
		  "laozi16",
		  "daodejing-i",
		  "laozi18"
});


void create()
{
		  set("short",HIM"�ؾ�����¥"NOR);

		  set("long",@LONG
������������ؾ�����¥����������Ҫ�������Ǵ���ڴˡ�ֻ����ǽ��һ
������ܣ������˵��̵ĵ伮��������һ�������εĴ����ӡ�����ž������˺�
�¡��˴������������أ�һ�����ǲ�������ġ�
LONG);

		  set("exits",([ "down" : __DIR__"jingge2.c",
							 ])
			  );
		  set("cost",1);

		  set("objects", ([
				 __DIR__"obj/"+books[random(sizeof(books))] : 1,
				 __DIR__"obj/"+books[random(sizeof(books))] : 1
		  ]));
		  setup();
}

int valid_leave(object me, string dir)
{
		  if (  (dir == "down")
			  && (!me->query_temp("qz_authorized",1) && !wizardp(me) )
			  ) {
				 message_vision("δ����ɣ������뿪���", me);
				return notify_fail("\n");
			  }

		  return ::valid_leave(me, dir);
}

