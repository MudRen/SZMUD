/* /kungfu/class/movie/npc/zhaodai
** 彩票行招待
** created by yujie
** created in 11/2001
*/

#include <ansi.h>
inherit NPC;

#define CAIPIAO "/kungfu/class/movie/obj/caipiao"
#define CPNUM "/data/movie/caipiao/cpnum"
#define CPSYS "/adm/single/cpsys"
#define JIANGDATA "/data/movie/caipiao/jiangdata"
#define NUMBAN "/data/movie/caipiao/numban"
#define TYPEJIANG "/data/movie/caipiao/typejiang"
#define PINANG "/kungfu/class/movie/obj/pinang"

#include <inttostr.h>

nosave string *jdata;

nosave string *typejiang;

string ask_pinang();

void create()
{
        set_name("临时招待", ({ "zhao dai","zhaodai" }));
        set("title","彩票行特派");
        set("long", "彩票行特聘招待，处理联系发奖的事宜\n");
        set("gender", "男性");
        set("age", 25);
        set("max_jing", 200);
        set("max_qi", 200);

        set("combat_exp", 0);
        set("shen_type", 1);

        set("inquiry", ([
                "彩票" : "你拥有的彩票可以交给我来帮你对奖，如果中奖我会通知负责人来发奖。\n",
                "皮囊" : (:ask_pinang:),
                "彩票行": "这里是负责发行福利彩票和举行开奖，对奖，发奖活动的行当。\n",
        ]));

        setup();
}

int query_jiangdata()
{
	string msg;
	if (file_size(JIANGDATA)<1)
		return 0;

	msg = read_file(JIANGDATA);
	jdata = explode(msg,"*");
	return 1;

}

int query_typejiang()
{
	string msg;

	if (file_size(TYPEJIANG)<1)
		return 0;

	msg = read_file(TYPEJIANG);
	typejiang = explode(msg,"*");
	return 1;
}

int accept_object(object me, object ob)
{
	object thisob = this_object();
	object where;
	int i ,zhong ,num ,thisnum;
	string jpin;
	object boss;

	where = environment(thisob);

	if (base_name(where)!= "/kungfu/class/movie/caipiaohang")
	{	command("say 还是等我回彩票行再说吧！");
		return 0;
	}

	if (base_name(ob) != CAIPIAO )
	{	command("say 你给我这个干吗？");
		return 0;
	}

	if ( query_jiangdata() == 0)
	{	command("say 现在还没有开奖，请随时留意公告和牌子上的开奖信息。");
		return 0;
	}

	zhong = 0;

	thisnum = ob->query("number");

	if (thisnum == 0)
	{	command("say 你这是一张废票，还是扔了吧。");
		return 0;
	}

	for(i=1; i<sizeof(jdata); i++)
		if (sscanf(jdata[i],"%s@%d@",jpin,num) == 2)
			if (num == thisnum)
			{	zhong = 1;
				break;
			}

	if (zhong == 0)
	{	command("say 很可惜，你这张的号码不是本期的中奖号码，请查询牌子上的中奖号码。");
		return 0;
	}

	CPSYS->add_type(tostring(i),me->query("id"),"0");
	message_vision(HIG"$N对着$n大声说道：恭喜你，你获得了本次福利彩票开奖的"+chinese_number(i)+"等奖！\n"NOR,thisob,me);
	message_vision(HIG"$N对着$n大声说道：你的奖品是："+jpin+"，我会立即通知负责人来为你颁奖。\n"NOR,thisob,me);
        CHANNEL_D->do_channel(this_object(), "sys", me->name() + "---"+ me->query("id")+"获得了本期福利彩票开奖活动的"+chinese_number(i)+"等奖。\n");
        CHANNEL_D->do_channel(this_object(), "sys", "请巫师们尽快过来为他颁奖，记得颁完后做个记号--mark");
        if ( objectp (boss = present("boss",where)))
        {	CHANNEL_D->do_channel(boss, "chat", me->name() + "（"+ me->query("id")+"）获得了本期福利彩票开奖活动的"+chinese_number(i)+"等奖。\n");
        	CHANNEL_D->do_channel(boss, "chat", me->name()+"的奖品是："+jpin+ "，我们会尽快为他颁奖，感谢大家的参与。\n");
        }

        return 1;
}

string ask_pinang()
{
	object me = this_player();
	object nang;

	if (me->query("get_pinang"))
		return "你已经拿过皮囊了，如果丢了退出重新进来的时候又会自动回来的。\n";
        if (present("pi nang",me))
                return "你身上已经有一个皮囊了。\n";

	nang = new(PINANG);
	nang ->set("owner",me->query("id"));
        me->set("get_pinang",1);
	nang ->move(me);
	message_vision("$N递给$n一个贴身皮囊。\n",this_object(),me);
	return "以后你的彩票就可以放进皮囊里，退出游戏或者死亡都不会丢失了。\n记得留意我们的公告，及时来查看您是否中奖，祝你好运！\n";
}
