// Code of ShenZhou
// kane, 20/5/97

inherit ROOM;
#include <localtime.h>

string* dirs = ({
	"east", "southeast", "southeast", "southwest", "northeast", "northeast",
	"west", "south", "south", "northwest", "north", "north",
	});


void create()
{

	set("short", "�һ���");
	set("long", @LONG
�������ƺ������޾�һ�㣬����С�������ݺύ��������˼����ƴ������
��ԭ�أ�������ת���ֻص���ԭ�ء�һ�����Σ��ƺ�ֻ����ͬһ���ط���Ȧ�ӡ�
LONG
	);

		set("exits", ([
		"east" : __DIR__"thzhen5",
		"south" : __DIR__"thzhen5",
		"west" : __DIR__"thzhen5",
		"north" : __DIR__"thzhen5",
		"northeast" : __DIR__"thzhen5",
		"southeast" : __DIR__"thzhen5",
		"southwest" : __DIR__"thzhen5",
		"northwest" : __DIR__"thzhen5",
		]));

	set("cost", 25);
	set("outdoors", "taohua");

	setup();

}
int valid_leave(object me, string dir)
{
  mixed local;
  int count;
  mapping myfam;

  myfam = (mapping)me->query("family");

  local = localtime(time()*60);

  count = ((local[LT_HOUR]+1)%24)/2;

  if (dirs[count] == dir) {
        me->move("/d/taohua/thzhen6");
/*        if (!myfam || myfam["family_name"] == "�һ���") {
          if (me->query("combat_exp")<50000+random(10000)) 
            me->add("combat_exp",random((me->query_skill("qimen-dunjia",1))/20));
          if (me->query("potential") < me->query("max_potential")
	  && me->query("combat_exp") < 200000+random(50000) )
            me->add("potential",random((me->query_skill("qimen-dunjia",1))/20));
          
        }
*/
        me->start_busy(random(3));
        return notify_fail("\n");
  }
  return ::valid_leave(me,dir);
}


