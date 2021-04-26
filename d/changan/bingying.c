//bingying for scheme do job
#include <ansi.h>;
#define BUSY_TIME 180

inherit ROOM;


void create()
{
        set("short","兵营");
        set("long",@LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，有的
独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地寻视着四
周。看到你进来，他们全都向你包围了过来，形势看来不太妙。
LONG
        );
        set("exits",([
                "east" : __DIR__"bydamen",
        ]));
        set("objects",([
                 __DIR__"npc/wujiang":1,
                 __DIR__"npc/bing":4,
        ]));
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
        if( (int)me->query("shen") < -100 ) 
              return notify_fail("教头看你不像好人，不愿意教你。\n");
        tell_object(me, CYN "\n你定了定神，开始跟着校场上的教头，一招一式地操练了。\n" NOR);
        me->set_temp("fengyao",1);
        me->add("balance",-5 );
        me->set("mp_job_time",time() );
        me->start_busy(60);
        me->set_temp("apply/short", 
                ({ HIW"长安城兵营 "NOR+me->query("name")+"("+capitalize(me->query("id"))+")"HIG" < 操 练 中 >"NOR""})); 
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
        if (dir =="east" && this_player()->query("scheming") )
        return notify_fail("看你木头木脑的，还是待在这里吧，要离开就先 scheme stop。\n");
        return ::valid_leave(me, dir);
}
