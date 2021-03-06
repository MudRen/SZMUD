// Code of ShenZhou
// kane, 20/5/97

inherit ROOM;
#include <localtime.h>
#define BUSY_TIME 180

string* dirs = ({
        "east", "southeast", "southeast", "southwest", "northeast", "northeast",
        "west", "south", "south", "northwest", "north", "north",
        });
string* dirs2 = ({
        "e", "se", "se", "sw", "ne", "ne",
        "w", "s", "s", "nw", "n", "n",
        });

void create()
{

        set("short", "桃花林");
        set("long", @LONG
这桃林似乎无穷无尽一般，其中小径更是纵横交错，匪夷所思。你拼命想离
开原地，但几个转折又回到了原地。一连几次，似乎只是在同一个地方兜圈子。
LONG
        );

                set("exits", ([
                "east" : __DIR__"thzhen2",
                "south" : __DIR__"thzhen2",
                "west" : __DIR__"thzhen2",
                "north" : __DIR__"thzhen2",
                "northeast" : __DIR__"thzhen2",
                "southeast" : __DIR__"thzhen2",
                "southwest" : __DIR__"thzhen2",
                "northwest" : __DIR__"thzhen2",
                ]));

        set("cost", 25);
        set("outdoors", "taohua");

        setup();

}
int valid_leave(object me, string dir)
{
  mixed local;
  int count,gain;
  mapping myfam;

  myfam = (mapping)me->query("family");

  local = localtime(time()*60);

  count = ((local[LT_HOUR]+1)%24)/2;
  gain = random((me->query_skill("qimen-dunjia",1))/30)+1;
  if (dirs[count] == dir || dirs2[count] == dir) {
        me->move("/d/taohua/thzhen3");
        if (time() > me->query("mp_job_time") + BUSY_TIME) {
if (me->query("combat_exp")< 200000 &&      me->query_skill("qimen-dunjia",1)>21) { 
                        me->add("combat_exp", 180 + random(40));
                        if (me->query("potential") < me->query("max_potential"))
                        me->add("potential", 60 + random(40));
                        me->set("mp_job_time",time() );
                }
        }
        me->start_busy(random(3));
        return notify_fail("\n");
  }
  return ::valid_leave(me,dir);
}
