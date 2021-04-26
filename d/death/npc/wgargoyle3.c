// Code of ShenZhou
// gargoyle.c  ���޳�
// snowlf change by 2000/12/05

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;
int ask_death();

string *death_msg = ({
	HIW "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,
	HIW "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
	HIW "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
	HIW "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
	HIW "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
	set_name("���޳�", ({ "white gargoyle", "gargoyle", "wuchang", "bai wuchang" }) );
	set("long",
		"���޳�������������ͷ�����㣬���׵����Ͽ������κ�ϲŭ���֡�\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	
	set("chat_msg", ({
//		(: this_object(), "random_move" :),
		"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",
		"���޳��ѳ�������ͷ��������������������Լ��ְ��ֳ�����ָ��\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("max_jing", 900);
	set("max_jingli", 900);
	set("max_qi", 900);
	set("max_neili", 900);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
        set("inquiry", ([
        
            "����һ��" : (: ask_death :),
            "����һ��" : (: ask_death :),
            "��һ��" : (: ask_death :),
            "death" : (: ask_death :),
            "again death" : (: ask_death :),
        ]));

	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object())
	||	wizardp(previous_object()) ) return;
	call_out( "death_stage", 30, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	int i;
	object *inv;
	if( !ob || !present(ob) ) return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

        inv =  all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
                DROP_CMD->do_drop(ob, inv[i]);
	if(ob->query("xkd/set", 1)) ob->move("/d/xiakedao/shatan");
	else ob->move(REVIVE_ROOM);
	message("vision",
		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
	return;
}


int ask_death() 
{
        object me = this_player();
	object ob;
	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
	
        command("say ����Ե�޹ʶ���һ�οɲ���С�£�");
        command("consider");	
        command("say �㲻������ʧ���5000 �Ľ������飬�������ÿ���书�����ή�뼶��");
        command("say ���Ҫ�ú����룡�������ˣ���������ı�������ɣ�");
        
//       tell_object(me,HIR"���޹ʶ���һ�οɲ���С�£��㲻������ʧ���5000 �Ľ������飬�������ÿ���书�����ή�뼶�����Ҫ�ú����룡\n");
//       tell_object(me,"�������ˣ���������ı������룺"NOR);      
        input_to("again_death", 1, ob);
	return 1;
}


private void again_death(string pass, object ob)
{
	object me = this_player();
	string old_pass;

	write("\n");
        old_pass = ob->query("check_password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("��������㲻����Ե�޹ʶ���һ�Σ�\n");
		return;
	}
	
	write("���޳�ҡ��ҡͷ��̾�˿�������"+HIC+"�㼴Ȼִ��Ҫ�޹ʶ���һ�Σ��Ǿ�ֻ�ó�ȫ���ˣ�\n"NOR);
	me -> set_temp("again_death" , "yes");
	me -> die();
	me -> delete_temp("again_death" , "yes");
	return;
}

