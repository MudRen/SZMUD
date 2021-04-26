// Code of ShenZhou
// road: /zhongnan/jingge2.c
// sdong 08/05/98 �ؾ����¥

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
		  set("short",HIM"�ؾ����¥"NOR);

		  set("long",@LONG
������������ؾ����¥�����ٽ��ڵ������Ǵ���ڴˡ�ֻ����ǽ��һ
������ܣ������˵��̵ĵ伮��������һ�������εĴ����ӣ�����Ҳ�������顣
һ����ͯ���������鼮��
LONG);

		  set("exits",([ "down" : __DIR__"jingge.c",
							  "up"	: __DIR__"jingge3.c",
							 ])
			  );
		  set("cost",1);

		  set("objects", ([
				 CLASS_D("quanzhen") + "/tan" : 1,
				 __DIR__"obj/"+books[random(sizeof(books))] : 1,
				 __DIR__"obj/"+books[random(sizeof(books))] : 1
		  ]));
		  setup();
}

int valid_leave(object me, string dir)
{
		  if (  (dir == "up")
			  && (!me->query_temp("qz_authorized",1) && !wizardp(me) )
			  ) {
				 message_vision("δ����ɣ����ý�����¥��", me);
				return notify_fail("\n");
			  }

		  return ::valid_leave(me, dir);
}


