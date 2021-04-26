// Code of ShenZhou
// Jay 8/9/96
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������",({ "ren woxing","ren" }) );
        set("gender", "����");
        set("age", 55);
	set("long",
		"�����׳��봹����ǰ���������������������ı������ݡ�\n");
      //  set("nickname","");
        set("title","�������ǰ����");
        set("combat_exp", 180000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set_skill("unarmed", 180);

	set_skill("force",180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
	set_skill("huagong-dafa",180);
	set_skill("sword",150);
	map_skill("force","huagong-dafa");

	set("max_neili",5000);
	set("neili",5000);
	set("jiali",100);
       setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/zhujian")->wield();
}

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if(!ob->query_temp("renqiu")) {
		command("say ��ʮ���겻�����������������øɸɾ����ˣ�"
			"�������̵����˸��ӣ�����Ҽ���β�͹��ɡ�");
		return 0;
	}
	command("say �Ϸ�ʮ���겻�����У���֪������ѧ�Ľ������ǲ��ǵá�");
	command("say �͸�������аɡ�");
	remove_call_out("bijian");
	call_out("bijian",1,me,ob);
	return 1;
}

void bijian(object ren, object player)
{
	object *ob, *inv;
	object liaokao;
	int i;

        message_vision(
                HIY "\n��Ȼ�䣬$N�������һ������ʯ���쾪��һ����Х��\n" NOR,
                 ren);

        ob = all_inventory(environment(ren));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==ren || ob[i]==player ) continue;
        tell_object(ob[i], "������˵�һ�������Ƕ��Ʊ��������ˣ�����һ����ѣ��\n");

		ob[i]->unconcious();
	}


        tell_object(player, "������˵�һ�������Ƕ��Ʊ��������ˣ�����һ����ѣ��\n");

	ren->remove_all_enemy();
	player->remove_all_enemy();
	liaokao=new(__DIR__"obj/liaokao");

	inv = all_inventory(player);
        for(i=0; i<sizeof(inv); i++)
            if( inv[i]->query("weapon_prop/damage"))
		destruct(inv[i]);

	player->set("startroom","/d/jiaxing/dilao");

	liaokao->move(player);
	player->move("/d/jiaxing/dilao");
//	call_out("zhenyun",1,player);
//        player->unconcious();
//        message_vision("�������ѹ����������к�"+player->name()+"����Ӱ�����ˡ�\n",
//		ren);
	destruct(ren);
	return;
}

//void zhenyun(object ob)
//{
//	ob->unconcious();
//}
int accept_object(object me, object obj)
{
        if ((string)obj->query("name")=="����") {
        message("vision",me->name()+"��������һֻ����\n",environment(me),
            ({me}));
	write("�㿴��������ת����ȥ���˼�������Ȼ��ת��������\n");
	command("say ��л�������Ϸ���ơ����Ǿ͹����аɡ�");
	me->set_temp("renqiu",1);
	return 1;
	}
}

