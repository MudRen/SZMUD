// Code of ShenZhou
// NPC mawude.c 马五德
// Acep
// For Beiming quest
// teller.c

inherit NPC;

int do_ask(string);
int do_say(string);

void create()
{
// use old code
	set("inquiry", ([
		"无量剑" :
"“无量剑”于五代后唐年间在南诏无量山创派，掌门人居住无量山剑湖宫。分东、\n"
"北、西三宗，北宗近数十年来已趋式微，东西二宗却均人才鼎盛。\n",
		"比武" :
"自于大宋仁过年间分为三宗之后，每隔五年，三宗门下弟子便在剑湖宫中比武斗剑，\n"
"获胜的一宗得在剑湖宫居住五年，至第六年上重行比试。五场斗剑，赢得三场者为\n"
"胜。北宗于四十年前获胜而入住剑湖宫，五年后败阵出宫，掌门人一怒而率领门人\n"
"迁往山西，此后即不再参预比剑，与东西两宗也不通音问。三十五年来，东西二宗\n"
"互有胜负。东宗胜过四次，西宗胜过两次。",
		"斗剑" :
"自于大宋仁过年间分为三宗之后，每隔五年，三宗门下弟子便在剑湖宫中比武斗剑，\n"
"获胜的一宗得在剑湖宫居住五年，至第六年上重行比试。五场斗剑，赢得三场者为\n"
"胜。北宗于四十年前获胜而入住剑湖宫，五年后败阵出宫，掌门人一怒而率领门人\n"
"迁往山西，此后即不再参预比剑，与东西两宗也不通音问。三十五年来，东西二宗\n"
"互有胜负。东宗胜过四次，西宗胜过两次。",
		"剑会" :
"自于大宋仁过年间分为三宗之后，每隔五年，三宗门下弟子便在剑湖宫中比武斗剑，\n"
"获胜的一宗得在剑湖宫居住五年，至第六年上重行比试。五场斗剑，赢得三场者为\n"
"胜。北宗于四十年前获胜而入住剑湖宫，五年后败阵出宫，掌门人一怒而率领门人\n"
"迁往山西，此后即不再参预比剑，与东西两宗也不通音问。三十五年来，东西二宗\n"
"互有胜负。东宗胜过四次，西宗胜过两次。",
		"观礼" :
"每逢斗剑会，东西二宗掌门人会共同出面邀请一些公证人，另外也邀请些武林中的\n"
"知名之士做为观礼的嘉宾。\n",
		"同去" : "这个...非常抱歉，鄙人现在很忙，不打算前往观礼这次的斗剑会了。\n",
		"独去" : "未被邀请的人是不会被准许上山的。再说你也不认识路。\n",
		"路"   : "去无量山的路？对不起，我也不认识。\n",
       ]) );
	setup();

}

void init()
{
	add_action("do_ask", "ask");
	add_action("do_say", "say");
}

int do_ask(string arg)
{
	object me;
	me=this_player();

	if (arg=="ma about 无量剑") { write("nod"); me->set_temp("asked",1); }
	if (arg=="ma about 比武"
		|| arg=="ma about 斗剑"
		|| arg=="剑会"
		&& me->query_temp("aksed")) {
		me->set_temp("asked", 2); }
	if (arg=="ma about 观礼" && me->query_temp("asked")==2) {
		me->set_temp("asked", 3); }
	if (arg=="ma about 同去" && me->query_temp("asked")==3) {
		me->set_temp("asked", 4); }
	if (arg=="ma about 独去" && me->query_temp("asked")==4) {
		me->set_temp("asked", 5); }
	return 0;
}

int do_say(string arg)
{
	object me;
	me=this_player();

	if (arg=="我非常想去观礼" && me->query_temp("asked")==5) {
		write("你拉着马五德央求，非要去无量山观礼不可。\n");
		me->set_temp("asked",6);
		return 1;
	}
	return 0;
}

int accept_object(object who, object ob)
{
	object bt;
		
	if (ob->query("money_id")
		&& ob->value()==80
		&& who->query_temp("asked")==6 
		&& present("gold", who)
		&& !query_temp("given"))
	{
		write("马五德点了点头，说道：“好吧，我给你写封拜贴，你自己去吧。”\n");
		say("马五德给了" + who->query("name") + "一封拜贴。\n");
		set_temp("given",1);
		who->delete_temp("asked");
		bt=new("/d/dali/obj/baitie");
		bt->move(who);
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		return 1;
	}
}

void destroying(object me, object obj)
{
	destruct(obj);
}
