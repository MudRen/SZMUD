// 调查npc
// questionary.c
// creat by shure@tomud.com 2002-04-15

inherit NPC;

#include <ansi.h>

string ask_form();

void create()
{
        set_name("屏羿", ({"ping yi", "ping", "yi"}));
        set("gender", "男性");
        set("nickname", HIW"天神使者"NOR);
        set("age", 1000);
        set("long",
                "他是来自神界的使者。\n"
                "他每年都会来到人间走上一遭，为一些问题寻求答案，探索世态民情。\n"
                "你可以问问他关于"HIR"调查"NOR"的事情\n"
                "或许可以通过他将自己的见解告诉给所有的人们。\n");

        set("inquiry", ([
                "问卷"       : (: ask_form :),
                "调查问卷"   : (: ask_form :),
                "调查"       : (: ask_form :),
                "问题"       : (: ask_form :),
                "all"       : "如果你要参加调查的活动就ask ping about 调查。",
        ]) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

string ask_form()
{
        object me;
        object ob;

        me = this_player();
        if( me->query("mud_age") < 1800 )
                return "请在注册后三十分钟内先熟悉本游戏。";

        ob = new( "/clone/misc/form" );
        ob->move(me);
        tell_object( me, HIG"屏羿神秘地笑了笑。\n"NOR );
        tell_object( me, HIG"屏羿说道：这次我奉命要调查的是关于文字mud的发展问题。\n"NOR );
        command( "say " + "你拿好这份「调查问卷」。" ); 
        return "输入"HIR" start "NOR + CYN"开始填写，详细介绍请 look questionary。";       
}