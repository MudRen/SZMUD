// Code of ShenZhou
// Summer 9/26/1996.

inherit NPC;

void create()
{
	set_name("ֵ������", ({ "zhiri lama", "lama" }));
	set("long", 
"���Ƕ�ĸ���ֵ�����ר�Ÿ�����־������\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "peaceful");
	set("class","lama");
	set("shen_type", 0);
	set("str", 22);
	set("int", 20);
	set("con", 22);
	set("dex", 21);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 10);
	set("combat_exp", 1000);

	set_skill("force", 20);
	set_skill("dodge", 25);
	set_skill("parry", 20);
	set_skill("strike", 20);


	setup();
	carry_object(__DIR__"obj/lamajiasha")->wear();
}
int accept_object(object me, object ob)
{
	object butter, gang;

	if (ob->name()!="���͹�") {
        write("ֵ����������¶���Ի�ı��顣\n");
        command ("shake");
	    remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        return 1;
	}
 	if ( objectp(butter = present("su you", ob)) && objectp(gang = present("tong gang", environment(this_object()))) ) {
		butter->move_liquid(gang);
        message_vision("$N������С������ĵ������ѩ���ڡ�\n", this_object());
	}
	if (me->query("class") == "lama"){ 
	if (me->query_skill("lamaism", 1) < 30){
	me->set("lama_butter",me->query("mud_age"));	
	command ("bow");
        command ("say ��������ʩ����");
	remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
	return 1;
	}
	if (me->query_skill("lamaism", 1) >= 30
	&& me->query_skill("lamaism", 1) < 60){
	me->set("lama_butter",me->query("mud_age") + 7600);
	command ("bow");
        command ("say ��������ʩ����");
	remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
	return 1;
        }
    }
	command ("say ��������ʩ����");
	remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
	return 1;
}
void destroy_it(object ob)
{
        destruct(ob);
	return ;
}


