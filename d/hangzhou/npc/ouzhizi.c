// Code of ShenZhou
// Ryu, 7/14/97

inherit NPC;
int ask_me();
int ask_sword();
int ask_iron();
void create()
{
	set_name("ŷ����", ({ "ou zhizi", "ou", "zhizi" }) );
	set("gender", "����" );
	set("age", 40);
	set("long",
		"һλ��΢�ԣ�����΢�����ߣ���Ȼ������˪��������ů��\n");
	set("combat_exp", 3000);
        set("str", 35);
        set("dex", 20);
        set("con", 20);
        set("int", 22);
	set("attitude", "friendly");
        set("inquiry", ([
		"����" : (: ask_me :),
		"�����" : "���Ǳ���Сͽ��\n",
		"Ѧ��" : "���Ǳ���Сͽ��\n",
		"����" : (: ask_sword :),
		"��ʯ" : (: ask_iron :),
		"����" : (: ask_iron :),
	]));	

	set_skill("dodge", 25);
	set_skill("parry", 25);
	set_skill("unarmed", 30);
	
	setup();
        carry_object("/d/city/obj/cloth")->wear();
	add_money("coin", 200);
}
int ask_iron()
{
	object ob, me = this_player();

	if (query("iron_done") == me->query("id")){
	command("nod");
	command("say �������򲻳�ʲô���������ѵ�Ҳ�м��ָֻ�����ȥ�ɡ�");
	ob = new("/clone/weapon/zijin-dao");
	ob->move(this_object());
	command("give " +me->query("id")+ " " + ob->query("id"));
	this_object()->delete("iron_done");
	return 1;
	}

	command("look "+me->query("id"));
	write("ŷ���ӵ���ͷ�������Ҳ���ǣ���ʼ��˼������\n");
	return 1;
}
int ask_sword()
{
	object ob, me=this_player();

	if (me->query_temp("wait_sword")){
	if (!query("sword_done")){
	command("say �����������������𣿲�Ҫ�ļ���");
	return 1;
	}
	else {
	ob=new("/clone/unique/yuchang-jian");
	ob->move(me);
	say("ŷ�����߽�����ȡ��һ��ֽ����ৣ���һ�����һ����������ı�����\n");
	message_vision("ŷ���ӵݸ�$Nһ���㳦����\n", me);
	set("sword_done", 0);
	set("sword_making", 0);
	me->delete_temp("wait_sword");
	command("say ����ȥ�ɣ�");
	command("rumor "+me->query("name")+"Ū����һ���㳦����");
	return 1;
	     }
	}
	else {return 0;}
}	
		
int ask_me()
{
	object ob;
	
	if (this_player()->query_temp("wait_sword") && !query("sword_done")){
        command("say �����������������𣿲�Ҫ�ļ���");
        return 1;
        }

	if (this_player()->query("age") < 20 || this_player()->query("combat_exp") < 15000){
	command("say �����Сë�������ڴ�Ȥ�Ϸ�ɣ���������ȥ��");
	return 1;
	}

	if (query("sword_making")){
	write("ŷ����˵�����ý�������ֻ����һ�ѣ��ѱ���Ŀ͹ٶ��ˣ��������������ɡ�\n");
	return 1;
	}
	ob=new("/clone/unique/yuchang-jian");
	if (ob){
	write("ŷ�����������°��������һ����˵�����͹�������һ��ʲ�����Ľ��ţ�\n");	
	this_player()->set_temp("marks/��", 1);
	add_action("do_say", "say");
	destruct(ob);
        return 1;
	}
	else{
	command("yawn "+this_player()->query("id"));
	command("zzz");
	return 1;
	}
}
int do_say(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	
	if( !me->query_temp("marks/��")) return 0;

	if( arg == "����" ){
	message_vision("$N˵���� ������\n", me);
	command("sneer");
	command("say ����Ϊ����һ���Ϻñ�����˵һ�仰��������");
	command("say ����ȥ׼�������ٽ������ʮ��ƽ���˵�ɡ�");
	me->delete_temp("marks/��");
	me->set_temp("marks/��", 1);	
	return 1;
	}
} 
int accept_object(object who, object ob)
{
	if (ob->query("for_blade")){
	write("ŷ�����۾�ͻȻһ�����ӹ�ʯ�����ش�����\n");
	call_out("say_ob", 10, ob, who);
	return 1;
	}

	if (!who->query_temp("marks/��")){
	command("? " +who->query("id"));
	return 0;
	}

	if (query("sword_making")){
        write("ŷ����˵�����ý�������ֻ����һ�ѣ��ѱ���Ŀ͹ٶ��ˣ��������������ɡ�\n");
        return 0;
        }

	if (ob->value() >= 1000000){
	command("nod " +who->query("id"));
	who->set_temp("marks/��", 1);
	call_out("destroy_it", 1, ob);
	if (who->query_temp("marks/��") >= 100000){
	who->delete_temp("marks/��");
        who->delete_temp("marks/��");
        who->set_temp("wait_sword", 1);
        set("sword_making", 1);
        command("say ����������ȡ���ɡ�");
        call_out("do_make", 700, who);
	      }
	return 1;
	}

	if (ob->query("material") == "steel"){
	if (ob->query("weapon_prop/damage") > 0){
	command("say �ⲻ�Ǻúõ�һ��"+ ob->query("name")+"�����ø�����ʲ�᣿");
	return 0;
	}
	else {
	command("nod");
	who->add_temp("marks/��", ob->query_weight());  
	if (who->query_temp("marks/��") >= 100000){
	if (!who->query_temp("marks/��")){
	command("say ����ʮ��ƽ��ɿ�¯�����ˡ�");
	}
	else {
	who->delete_temp("marks/��");
	who->delete_temp("marks/��");
	who->set_temp("wait_sword", 1);
	set("sword_making", 1);
	command("say ����������ȡ���ɡ�");
	call_out("do_make", 700, who);
	     }
	}
	call_out("destroy_it", 1, ob);
	}
	return 1;
	}
	else {
	command("say ��鶫���ɴ򲻳���������");
	return 0;
	}
}
void say_ob(object ob, object who)
{
	if (present(who, environment(this_object()))){
	command("hmm " +who->query("id"));
	command("say ��������������ƺ��е��ã���������������ҿ��ܲ���Ū��ʲô���á�");
	call_out("make_ob", 500, who);
	}

	if(objectp(ob)) destruct(ob);
	return;
}
	
void destroy_it(object ob)
{
	if(objectp(ob)) destruct(ob);
	return;
}
void do_make()
{
	set("sword_done", 1);
	return;
}
void make_ob(object who)
{
	set("iron_done", who->query("id"));
	return;
}
