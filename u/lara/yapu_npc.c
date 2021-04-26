// Code of ShenZhou
// yapu_npc.c ���ͺ�ѡ
#include <ansi.h>
#include <room.h>

inherit NPC;
int auto_perform();

void create()
{
	switch( random(7) )
	{
	case 0:
	set_name("С��", ({ "xiao fan", "seller", "fan" }) );
	set("long","���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
	set("gender", "����");
	set("age", 32);
	set("real_name","���");
	set("real_long", "����һ��ɱ�˲�գ�۵ĵ��ˣ�ƾ��һ�������Ĵ�����°�ӣ�ɱ�˷Ż�������Ϊ��\n");
	set("real_title", "ɽկͷĿ");
	set("real_menpai", "huashan");
		break;
	case 1:
	set_name("����", ({ "shu sheng", "sheng" }) );
	set("long","���Ǹ�����ʫ�飬ȴ���޲���֮��������������\n");
	set("gender", "����");
	set("age", 18 + random(4));
	set("int", 30);
	set("real_name","ɱ��");
	set("real_long", "��ԭ���ǵ���һ����͢����������̰ͼ�ػߣ����Ͷ�������\n�����͢������ɱ��ԭ��Ա���ֶ����ݴ����������������������������ϡ�\n");
	set("real_title", "�����ϸ");
	set("real_menpai", "dajin");
		break;
	case 2:
	set_name("������", ({ "tangzi shou","shou" }) );
	set("gender", "����");
	set("age", 30);
	set("real_name","���");
	set("long","���Ǹ��ھ������֣����û���������һ���������\n");
	set("real_long", "�����������ư��е�һ������С�䣬�������г����Բ��ڴ�ʱɱʦ���ţ�\n���߱����书�ؾ���������һ�����������վ��죬�Ĵ�Ϊ��������\n");
	set("real_title", "���ư�");
	set("real_menpai", "tiezhang");
		break;
	case 3:
	set_name("ɮ��", ({ "seng ren", "seng"}));
	set("long","����һλɮ�ˡ�\n");
	set("gender", "����");
	set("age", 35);
	set("class", "bonze");
	set("real_name","�ƽ�ɮ");
	set("real_long", "����������һ�����ָ�ɮ���£����ڲ�����棬ʱ����ʦ���ǳ⡣\n���书�г��ᣬ��Ϊ�������ģ���Ȼ����ɱ����ҵ��ʦ���ӳ������£�Ͷ�����������š�\n");
	set("real_title", "����ŵ���");
	set("real_menpai", "shaolin");
		break;
	case 4:
	set_name("����", ({ "hu ren", "ren", "foreigner" }));
	set("long", "һ���𷢱��۵ĺ��ˣ���ֺ�������ߺ���š�\n");
	set("gender", "����");
	set("age", 30 + random(10));
	set("real_name","�ɹ��佫");
	set("real_long", "����һ���������򷬰����ʿ������Ϊ��������͵ѧ�ü�����������\nͶ���ɹž���֮���������ã�ְȨҲ��С��\n����Ȼ���£�����ȴʮ�ֲ��̣�ʱ�����������ɱ����Ϊ�֣����˷�ָ��\n");
	set("real_menpai", "xiyu");
		break;
	case 5:
	set_name("�", ({ "poor man", "man" }));
	set("gender", "����");
	set("age", 53);
	set("long", "һ���������������ɫ�����\n");
	set("real_name","��������");
	set("real_long", "�������ڽ�����֧��һ������������ڳ�����ѧ�����֮���յ���\nһ���ﰵ����ȡ������ѧ�伮��ɱ�˿��ܵ�ͬ��ʦ�ֵܣ��ӵ���ԭǱ��������\n��Ϊ���¶��ݣ�������ɱ�޹�����������Ҳ�������ǽ塣\n");
	set("real_title", "������֧");
	set("real_menpai", "mizong");
		break;
	case 6:
	set_name("Ů��",({ "girl" }) );
	set("gender", "Ů��" );
	set("age", 16+random(3));
	set("long", "���Ǹ�ũ����Ů����Ȼֻ��ʮ���꣬����Ѿ���ʼ������\n");
	set("real_name","�置��Ů");
	set("real_long", "����������һ��С�������Ů����ʱ��Ϊ��������йƶ����������Ͷ�������ɣ�\n�������ڻ���书֮�У�������ᣬ���边Ҳ���������������޵����ദ�����ĿȾ֮�£�\n����Ҳ������սƻ���Ϊ����������ƽ�׺����˲�������ͬ����\n");
	set("real_menpai", "miaojiang");
		break;
	}
	set("str", 20);
	set("con", 20);
	set("int", 20);
	set("dex", 20);

	set("attitude", "peaceful");
	set("combat_exp", 10000);
	set("yapu_target",1);
	
	set("chat_chance", 6);
	set("chat_msg", ({ (: random_move :) }));

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) ); 

	setup();
	carry_object("/clone/misc/cloth")->wear();
}


int checking(object me, object victim)
{
	victim = this_player();
	if ( !victim ) return 1;
	if (!query("real_face")) return 1;
/*
	if ( !victim = find_player(me->query("th_victim")) 
	&& victim->query("combat_exp") > me->query("combat_exp") ) {
	     message_vision("$N���˸����У��Ǳ����������˿�ȥ��\n", me);
	     destruct(me);
	     return 1;
	}
*/
	if ( victim->is_ghost() && living(me)) {
	     command("grin");
	     command("say ��ץ"+RANK_D->query_self_rude(me)+"�������������ף�");
	     message_vision("$N��Ц�������ﳤ��ȥ��\n", me);
	     destruct(me);
	     return 1; 
	}

	else if ( !me->is_fighting() && me->query("real_face") && living(me)) {
	     command("kick corpse");
	     command("say ��ץ"+RANK_D->query_self_rude(me)+"�������������ף�");
	     message_vision("$N��Ц�������ﳤ��ȥ��\n", me);
	     destruct(me);
	     return 1;
	}

	remove_call_out("checking");
	call_out("checking", 1, me, victim);
	return 1;
}

int accept_fight(object victim)
{
	object me = this_object();

	if (!query("real_face")) return 1;
	if (!living(me)) return 1;

	if (is_fighting() && me->query("th_victim") 
	&& me->query("th_victim")!= victim->query("id") 
	&& victim->query("combat_exp") > me->query("combat_exp") ) {
	      command( "say ��һ��ȥ��" );
	      return 0;
	}
	else {
	     command("say �ߺߣ�"+RANK_D->query_self_rude(me)+"������������ȥ��" );
	     me->kill_ob(victim);
	     remove_call_out("checking");
	     call_out("checking", 1, me, victim);
	     return 1;
	}
}

int accept_kill(object victim)
{
	object me = this_object();

	if (!query("real_face")) return 1;
	if (!living(me)) return 1;

	if (is_fighting() && me->query("th_victim") 
	&& me->query("th_victim")!= victim->query("id") 
	&& victim->query("combat_exp")*3/2 > me->query("combat_exp") ) 	
	{
	    	command("say ���ж�Ϊʤ��"+RANK_D->query_self_rude(me)+"�ɲ������ˣ�");
	     message_vision("\n$NͻȻ��һ����������սȦ�����ˣ�\n", me);
	     remove_call_out("checking");
	     me->remove_all_enemy();
	     destruct(me);
		return 1;
	}
	else {
	     command( "say ����"+RANK_D->query_rude(victim)+"Ҳ����"+RANK_D->query_self_rude(me)+"����ȥ������һ�����ˣ�" );
	     me->kill_ob(victim);
	     remove_call_out("checking");
	     call_out("checking", 1, me, victim);
	return 1;
	}

}

void unconcious()
{
	object me = this_object();
	remove_call_out("checking");
	me->disable_player(" <���Բ���>");
	me->set("jing", 0);
	me->set("qi", 0);
	COMBAT_D->announce(me, "unconcious");
	call_out("revive", random(100 - query("con")) + 30);
}

void die()
{
	object corpse;
	mixed killer;

	remove_call_out("checking");
	
	if( !living(this_object()) ) revive(1);
	COMBAT_D->announce(this_object(), "dead");

	if( objectp(killer = query_temp("last_damage_from"))){
	     set_temp("my_killer", killer->query("id"));
	     COMBAT_D->killer_reward(killer, this_object());
	}

	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	     corpse->move(environment());
	     corpse->delete("combat_exp");
		corpse->set("th_victim",query("th_victim"));
		corpse->set("yapu_fail",query("th_victim"));

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
	
	destruct(this_object());

}

int random_move()
{
	mapping exits, doors;
	string *dirs, dir;
	object me=this_object();

	if (is_fighting() || is_busy() || !living(me))
	     return 0;

	if (!me->query("steps")) {
	     remove_call_out("destroying");
	     call_out("destroying",1200,me);
	}

	if (me->query("steps")>=25) {
	     remove_call_out("destroying");
	     call_out("destroying",1,me);
	     return 0;
	}

	me->add("steps",1);

	if (!objectp(environment()) 
	     || !mapp(exits = environment()->query("exits")) 
	|| query("jingli") < query("max_jingli") / 2 )
	     return 0;

	dirs = keys(exits);

	if (this_object()->query("race") == "����"
	     && mapp(doors = environment()->query_doors()))
	     dirs += keys(doors);

	if (sizeof(dirs) == 0) return 0;
	dir = dirs[random(sizeof(dirs))];

	if (mapp(doors) && !undefinedp(doors[dir])
	     && (doors[dir]["status"] & DOOR_CLOSED) )
	     command("open " + dir);

	command("go " + dir);
	return 1;
}

void destroying(object me)
{
	message_vision("$N���˿����⣬�������µ��뿪�ˡ�\n",me);
	destruct(me);
	return;
}

#include "yapu_auto_perform.h"
