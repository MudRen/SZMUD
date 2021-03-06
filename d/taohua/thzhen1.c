// Code of ShenZhou
// Chaos, 3/10/97

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
你一走进桃林，看见东一簇桃花，西一丛桃树，顿时目眩神迷，迷失了方向。
你慌乱中刚想退出，回头一瞧，来路已在花丛中消失得无影无踪，看来只有硬着头
皮往前走了。
LONG
        );

                set("exits", ([
                "east" : __DIR__"thzhen1",
                "south" : __DIR__"thzhen1",
                "west" : __DIR__"thzhen1",
                "north" : __DIR__"thzhen1",
                "northeast" : __DIR__"thzhen3",
                "southeast" : __DIR__"thzhen3",
                "southwest" : __DIR__"thzhen3",
                "northwest" : __DIR__"thzhen3",
                ]));


        set("cost", 25);
        set("outdoors", "taohua");

        setup();

}

int valid_leave(object me, string dir)
{
  mixed local;
  int count, gain;
  mapping myfam;

  myfam = (mapping)me->query("family");

  local = localtime(time()*60);

  count = ((local[LT_HOUR]+1)%24)/2;
  gain = random((me->query_skill("qimen-dunjia",1))/30)+1;
  if (dirs[count] == dir || dirs2[count] == dir) {
        me->move("/d/taohua/thzhen2");
        if (time() > me->query("mp_job_time") + BUSY_TIME) {
if (me->query("combat_exp")< 200000 && me->query_skill("qimen-dunjia",1)>21) {
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
