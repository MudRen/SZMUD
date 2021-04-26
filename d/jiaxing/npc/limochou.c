// Code of ShenZhou
// Jay 3/21/96

#include <ansi.h>


inherit NPC;

int do_look(string);
string ask_me();

void create()
{
        set_name("��Ī��", ({ "li mochou", "li", "mochou" }));
        set("long", "�����ü�Ϊ��ò���������Ŀ�����˲���������\n");
	set("nickname", "��������");
        set("gender", "Ů��");
        set("rank_info/respect", "����");
        set("age", 27);
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 17);
        set("int", 25);
        set("shen_type", -1);

        set_skill("cuff", 140);
	set_skill("ding-dodge", 160);
	set_skill("meinu-quan", 150);
        set_skill("force", 150);
        set_skill("dodge", 160);
	set_skill("whip",170);
	set_skill("feifeng-bian",170);
        set_skill("taiji-shengong",150);

	map_skill("dodge", "ding-dodge");
	map_skill("cuff", "meinu-quan");
        map_skill("force", "taiji-shengong");
	map_skill("whip","feifeng-bian");

	prepare_skill("cuff", "meinu-quan");

        set("jiali",50);
        set("combat_exp", 1300000);

        set("max_qi", 1800);
        set("max_jing", 1200);
        set("neili", 2000);
        set("max_neili", 2000);

        set("inquiry", ([
            "name" : "վԶ�㣡",
            "here" : "�Ҳ��Ǳ����ˣ���֪����",
            "��" : "����������������˼֮�ࡢ���֮�⣿",
            "½չԪ" : "�����Ǹ������С������ʲô��",
	    "�����" : (: ask_me :),
            "С��Ů" : "�����ҵ�ʦ�á����������ʲô��",
            "�ֳ�Ӣ" : "�����ҵ�ʦ�棬�������ʵ�����ʣ�С���������㡣",
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
            "��Ī���������裬�������񣬸�����������䣬���Ǻ��ֱ������������\n",
            "��Ī�����������ϵر�˫�ɿͣ��ϳἸ�غ����\n",
            "��Ī�����������Ȥ�����࣬���и��гն�Ů����\n",
            "��Ī���������Ӧ�����������ƣ�ǧɽĺѩ��ֻӰ��˭ȥ����\n",
            "��Ī����Ɐ�У��������ǰ�Թ�������������·����į������ġ���������ƽ������\n",
            "��Ī���������л�Щ��ർ���ɽ��������ꡣ��\n",
            "��Ī���������Ҳ�ʣ�δ���ˣ�ݺ�����Ӿ��������\n",
            "��Ī�������ǧ����ţ�Ϊ����ɧ�ˣ����ʹ�����������𴦡���\n",
        }) );

        carry_object("/clone/weapon/fuchen")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();

}

void init()
{
        ::init();
        add_action("do_look","look");
        add_action("do_look","hug");
        add_action("do_look","mo");
        add_action("do_look","18mo");
        add_action("do_look","kiss");

}

int ask_me()
{
        object me;
 
        me = this_player();
	   message("vision",
   HIY "��Ī����Цһ���������������ȥ������\n"
       "��Ī�����ɱ��" + me->name() +"\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
   return 1;
}
  

int do_look(string target)
{
        object me;
 
        me = this_player();
        if (target=="li" || target=="li mochou" || target=="mochou" ) 
           if ((string)me->query("gender") == "����") {
		   message("vision",
   HIY "��Ī���ŭ���ȵ��������������Щ����ĳ����ˣ�ȥ���ɣ�\n"
       "��Ī�����ɱ��" + me->name() +"����\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
           }
}       
