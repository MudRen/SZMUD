 // Code by Scatter
// 黑风崖
// gate.c
#define SAVE_NPC "/family_job/savenpc"
inherit ROOM;

void create()
{
set("short", "黑风崖顶");
        set("long", @LONG
这里就是传说中的黑风崖的山脚。到这里你马上感觉到这里的无比的阴气，
以及一种说不出来的邪气。这里有一个牌子写这三个字 - 杀无赦 - 突然你
发现已经没有退路了，只有合力杀掉黑风崖的黑风祭才能回到中原。你往上
一看结果发现看不到山顶，可想而知这座山的路一定不好走。
(BETA 测试版V9.0 如果所有 NPC 都杀掉了, 请打 complete)
LONG );

        set("exits", ([
                "southdown"  : __DIR__"hill17",
        ]));

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_finish", "complete");
}

int do_finish(string arg)
{
        object me=this_player();
        string fname, pdata, ropen;
        int maxkillnum, killnum;

        fname = "fjob/mp/killnum";
        ropen = SAVE_NPC->do_load(fname);
        killnum = atoi(ropen);

        fname = "fjob/mp/maxkillnum";
        ropen = SAVE_NPC->do_load(fname);
        maxkillnum = atoi(ropen);

        if(maxkillnum != killnum)
        {
                write("你的第六感告诉你任务并没有完成！\n");
                return 1;
        }

        write("\n感谢你测试多人合作模式 FAMILY_JOB BETA V9.0 (抢先测试版)\n你获得 2000 点经验直以及潜能全满\n");
        me->add("combat_exp", 2000);
        me->set("potential", me->query("max_potential"));
        me->move(me->query_temp("family_job/rplace"));
        return 1;
}
