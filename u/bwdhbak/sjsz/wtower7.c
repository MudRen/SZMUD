// Code of ShenZhou
// sdong, 3/18/2000

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create()
{
        set("short","��̨");

        set("long",@LONG
�����Ȼ��һ���߸ߵ���̨�����������������š���������Կ����Խ�ɽׯ
��ÿһ�����䣬������ש���ߣ�������ޡ����������ڲص�ɱ����ȴ���˲�����
���������ָ��֣�һ�����ӵ������Դ���
LONG);

          set("exits",([ 
                         "down" : __DIR__"wtower6",
                      ])
              );
	    set("objects", ([
		  __DIR__"obj/pao"     : 1,
		  __DIR__"obj/huoyao"     : 2,
		  __DIR__"obj/dantou"     : 5,
		 ]));
          set("cost",3);
          set("outdoors", "city");
		  create_room();
          setup();
}

void init()
{
        init_room();
}
