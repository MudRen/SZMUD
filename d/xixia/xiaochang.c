//bingying for scheme do job
#include <ansi.h>;
#define BUSY_TIME 180

inherit ROOM;

void create()
{
        set("short", "小校场");
        set("long", @LONG
这里是骠骑营的小校场，平时军士们就在这里操练，地上很平整，
居中是指挥台，有根长达数丈的旗杆，杆顶一面绣着一条红龙的骠骑
营白色军旗迎风猎猎作响。平时军士们一天三练，早上出操，中午出
城练马术和野战，晚上则负责皇城外的巡逻。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"biaoqiyin",
		]));
        set("objects", ([
                __DIR__"npc/xxbing2" : 3,
                __DIR__"npc/wujiang" : 1,
        ]));
        set("cost", 1);
        set("outdoors", "xixia");
        set("no_fight",1);
        setup();
}

void init()
{
        add_action("do_fengyao","caolian");
}

int do_fengyao()
{
        object me = this_player();
        int bonus,exp,pot;
        object mon;
        if( time() < me->query("mp_job_time") + BUSY_TIME ) 
              return notify_fail("刚刚操练完，休息一下吧。\n");
        if( (int)me->query_temp("fengyao") ) 
              return notify_fail("你已经在工作了。\n");
        if( (int)me->query("balance") < 5 ) 
        {
              tell_object(me,HIR"\n每次操练你的钱庄至少必须有五个铜钱。\n\n\n"NOR);
              return 1;
        }
        if( (int)me->query("combat_exp") < 100000 ) 
              return notify_fail("你的武功太差，还是先去练些基本功吧(100k 经验)。\n");
        if( (int)me->query("shen") > 100 ) 
              return notify_fail("教头看你象奸细，不愿意教你。\n");
        tell_object(me, CYN "\n你定了定神，开始跟着校场上的教头，一招一式地操练了。\n" NOR);
        me->set_temp("fengyao",1);
        me->add("balance",-5 );
        me->set("mp_job_time",time() );
        me->start_busy(60);
        me->set_temp("apply/short", 
                ({ HIW"西夏兵营 "NOR+me->query("name")+"("+capitalize(me->query("id"))+")"HIG" < 训 练 中 >"NOR""})); 
        call_out("del_fengyao", 120, me, mon, bonus, exp, pot);
        return 1;
}

void del_fengyao(object me, object mon, int bonus, int exp, int pot)
{
        me->delete_temp("fengyao");
        tell_object(me,HIB"\n与大军一起进行操练，你感觉精神百倍，斗志昂扬。\n\n\n"NOR);
        tell_object(me,HIY"虽然累得腰酸背痛，不过你总算长了一些打斗经验。\n\n\n"NOR);
        me->add("combat_exp",50 + random (40));
        me->delete_temp("apply/short"); 
        me->add("caolian/ca",1);
        return ;
}

int valid_leave(object me, string dir)
{
        if (dir =="north" && this_player()->query("scheming") )
        return notify_fail("看你木头木脑的，还是待在这里吧，要离开就先 scheme stop。\n");
        return ::valid_leave(me, dir);
}
