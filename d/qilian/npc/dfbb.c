// Code of ShenZhou
#include <ansi.h>
inherit NPC;

int ask_pixie();
int ask_liandan();
//int auto_perform();

void create() 
{
	set_name("��������", ({ "dongfang bubai", "dongfang", "bubai" }));
	set_color("$HIW$");
	set("title", "������̽���");
	set("long", "���˱��Ƕ�ȡ��������̽���֮λ��ʮ�������ų��书���µ�һ�Ķ������ܡ�\n"
		"���Ǵ˿�������˺��룬���Ͼ�Ȼʩ��֬�ۣ������Ǽ�����ʽ���в��С�Ů��\n"
		"Ů����ɫ֮�����㴩��ӯӯ���˵���Ů���ϣ�Ҳ�Ե�̫���ޡ�̫������Щ����\n"
		"��һλ���춯�ء������������ֹֽܾ������ģ����\n");
	 set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("canuse_guimei",1);
	set("canuse_cixin",1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 10000);
	set("max_jing", 15000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("max_jingli", 15000);
	set("jingli", 15000);
	set("jiali", 300);
	set("combat_exp", 6400000);
    set("shen_type", -1);
        set("shen", -6400000);



	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("strike", 400);
	set_skill("pixie-jian", 400);
	set_skill("taiji-shengong",400);

    map_skill("force", "taiji-shengong");
    map_skill("dodge", "pixie-jian");
    map_skill("parry", "pixie-jian");
    map_skill("sword", "pixie-jian");
    set("no_get", "�뽫�������ߣ����Σ�");

/*	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
*/
	set("inquiry", ([
		"��а����" : (: ask_pixie :),
		"����" : (: ask_liandan :),

	]));

	setup();
	carry_object("/d/quanzhou/obj/xiuhua")->wield();
	carry_object("d/city/obj/pink_cloth")->wear();

}
int ask_liandan()
{
	object me = this_player();
	object ob = this_object();
	string a1,a2,a3,a4,a5;
	string b1,b2,b3,b4,b5;
	int random_a;
		if(me->query_skill("pixie-jian", 1) <1)
	{
		message_vision("$N��$p����˵�����㲢δ��ϰ��а����ѽ����ū�����������\n", ob,me);
		return 1;
	}
	if(me->query_skill("pixie-jian", 1) <200)
	{
		message_vision("$N��$p����˵�������а������Ϊ����ܸߣ����赤ҩ����������\n", ob,me);
		return 1;
	}
	if(me->query("can_dfbb")!=1)
	{
		message_vision("$N��$p����˵������Ϊ��������������������٣��������������\n", ob,me);
		return 1;
	}

	if(me->query("drug_list"))
	{
		message_vision("$N��$p����˵�����㲻��֪���ط���Ҫ������������\n", ob,me);
		return 1;
	}
	message_vision("$N��$p����˵������Ȼ�������ҽ̣��Ҿͽ����������ط�����֪�㡣\n", ob,me);
	message_vision("$N��ָ�ɿ���$p������Ѩ�����˵�ͷ��\n", ob,me);

	random_a=random(3);
	if(random_a==1)
	{
		a1="�޻���";
		b1="wuhua guo";
	}
	else
		if(random_a==2)
		{
			a1="������";
			b1="yinyang cao";
		}
		else
		{
			a1="������";
			b1="kuihua fen";
		}

	random_a=random(3);
	if(random_a==1)
	{
		a2="�޻���";
		b2="wuhua guo";
	}
	else
		if(random_a==2)
		{
			a2="������";
			b2="yinyang cao";
		}
		else
		{
			a2="������";
			b2="kuihua fen";
		}

random_a=random(3);
	if(random_a==1)
	{
		a3="�޻���";
		b3="wuhua guo";
	}
	else
		if(random_a==2)
		{
			a3="������";
			b3="yinyang cao";
		}
		else
		{
			a3="������";
			b3="kuihua fen";
		}
random_a=random(3);
	if(random_a==1)
	{
		a4="�޻���";
		b4="wuhua guo";
	}
	else
		if(random_a==2)
		{
			a4="������";
			b4="yinyang cao";
		}
		else
		{
			a4="������";
			b4="kuihua fen";
		}
		random_a=random(3);
	if(random_a==1)
	{
		a5="�޻���";
		b5="wuhua guo";
	}
	else
		if(random_a==2)
		{
			a5="������";
			b5="yinyang cao";
		}
		else
		{
			a5="������";
			b5="kuihua fen";
		}
	message_vision("\n$N��$p����˵�������谴�ռ�����˳��ȥ������ǧ����á�\n"
		HIW"��ҩ���ط���"+a1+"��"+a2+"��"+a3+"��"+a4+"��"+a5+"��ÿ�����а�������ʱ�ͳ�һ����\n"NOR
		"\ҩ����ֻ˵һ�Σ������˿ɾ���Զ�������ˣ��мǡ�\n"
		"\���ˣ��Ҹ�ȥ����ͤ�ˣ���������������������࣬�ҵö��������\n"
		"$N�������˳�ȥ��\n",ob,me);
		
		me->set("drug_list/1",b1);
		me->set("drug_list/2",b2);
		me->set("drug_list/3",b3);
		me->set("drug_list/4",b4);
		me->set("drug_list/5",b5);
		me->delete("can_dfbb");
		destruct(this_object());

	return 1;
}

int ask_pixie()
{
	object book;
	object me = this_player();
	object ob = this_object();
	
	if(me->query_skill("pixie-jian", 1) <1)
	{
		message_vision("$N��$p����˵�����㲢δ��ϰ��а����ѽ����ū�����������\n", ob,me);
		return 1;
	}
	if(me->query_skill("pixie-jian", 1) <120)
	{
		message_vision("$N��$p����˵�������а������Ϊ̫������ϰ������ū�Ұɡ�\n", ob,me);
		return 1;
	}
	if(me->query("can_dfbb")!=1)
	{
		message_vision("$N��$p����˵������Ϊ��������������������٣��������������\n", ob,me);
		return 1;
	}

	
	if(me->query("canuse_cixin")==1&&me->query("canuse_guimei")==1)
	{
		message_vision("$N��$p����˵�������������а�����ľ�Ҫ��ū��û��ʲô���Դ�������ˡ�\n", ob,me);
		return 1;
	}
    if ( query("book_count") <0)
	{
		message_vision("$N��$p����˵��������ū�����Ӳ��ʣ�ʲô����Ҳ��Ը��ش�\n", ob,me);
		return 1;

	}
	if(me->query("canuse_guimei")==1)
	{

		book = new(__DIR__"obj/cixin_book");
		book->move(me);
        add("book_count", -1);
		message_vision("$N��$p����˵���������б�С���ӣ�����ȥ���ɣ�Ҳ������а����������ߡ�\n", ob,me);
		book->set("master",me->query("id"));


	}
	else{
		book = new(__DIR__"obj/guimei_book");
		book->move(me);
        add("book_count", -1);
		message_vision("$N��$p����˵���������б�С���ӣ�����ȥ���ɣ�Ҳ������а����������ߡ�\n", ob,me);
		book->set("master",me->query("id"));


	}
		message_vision("$N��$p����˵�������ˣ��Ҹ�ȥ����ͤ�ˡ�\n", ob,me);
		message_vision("$N�������˳�ȥ��\n", ob,me);
		me->delete("can_dfbb");
		destruct(this_object());
		return 1;

}

