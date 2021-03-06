//Cracked by Yujie
inherit NPC;

int ask_set();

void create()
{
        set_name("香主侍从", ({ "shi cong","shicong"}) );
        set("gender", "女性" );
        set("age", 17);
        set("long","她是专门挑选出来侍侯长乐帮的香主的婢女。\n");
        set("str", 12);
        set("dex", 20);
        set("con", 13);
        set("shen_type", 0);
        set("combat_exp", 200);
        set("max_qi", 200);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("attitude", "friendly");
        set("inquiry", ([
            "set" : (: ask_set :),
            "here" : (: ask_set :),
        ]) );
        setup();
}

int ask_set()
{
        object me = this_player();
        
        if ( !stringp(me->query("clbpos")) )
        {	message_vision(query("name")+"对着$N摇了摇头，说道：你不是本帮的香主，我不告诉你。\n",me);
        	return 1;
        }
        
        write("侍从向你解释道：\n");
        write("在香主您自己的房子里可以做很多事情。\n");
        write("可以自己装饰自己的房间（用modify写房间描述）。\n");
        write("还可以邀请（invite）朋友来您的私房里玩。\n");
        write("甚至还能随意地设置自己房间是否允许战斗（用nofight和canfight设置）。\n");
        write("在自己的房间里您可以安心地练功睡觉，没有别人能来干扰你。\n");
        
        return 1;
}
