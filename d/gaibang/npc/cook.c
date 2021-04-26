// Code of ShenZhou
// d/gaibang/npc/cook.c ؤ���������
// xbc 06/22/1997

#include <ansi.h>

inherit NPC;

string ask_me(string, object);

void create()
{
	set_name("С�л�", ({"beggar", "jiao hua", "cook"}));
	set("title", "ؤ���������");
	set("gender", "����");
	set("age", 17);
	set("long", 
		"���������ؤ������Ũü���ۣ���ͷ�Ͼ��Ǻ��顣����������һ�Ѵ��ף������ղ�������\n");

	set("chat_chance", 1);
	set("chat_msg", ({
		"С�л������������������ʲô�˺��أ�\n",
		"С�л�ץ��һ��Ĩ�����Ѵ�����˲����ŵ����Ͽ�ʼ���ˡ�\n",
		"С�л�����һ���ʯͷ�ϣ�������ǰ�����ַ�������� \n",
		"����һ��ϤϤ�����ĽŲ�����С�л������������������������������\n",
	}) );

        set("inquiry", ([
                "here"   : (: ask_me, "zhulin":),
                "rumors" : (: ask_me, "yaoyan"  :),
		"����" : (: ask_me, "cook" :),
		"�ղ�" : (: ask_me, "cook" :),
		"����" : (: ask_me, "cook" :),
		"���߹�" : (: ask_me, "hong" :),
		"���ϰ���" : (: ask_me, "hong" :),
		"ţ����" : (: ask_me, "beef"  :),
		"���˭������÷" : (: ask_me, "beef" :),
                "������"   : (: ask_me, "soup" :),
		"���ײ�" : (: ask_me, "baicai" :),
		"������" : (: ask_me, "doufu" :),
		"��ʮ��������ҹ" : (: ask_me, "doufu" :),
        ]));

	set("attitude", "friendly");
	set("str", 20);
	set("int", 18);
	set("con", 21);
	set("dex", 21);

	set("rank", 2);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 180);
	set("max_neili",180);
	set("jiali", 20);
	
	set("combat_exp", 12000);
	
	set_skill("force", 25); 
	set_skill("huntian-qigong", 25); 
	set_skill("hand", 25); 
	set_skill("shexing-diaoshou", 25); 
	set_skill("dodge", 25); 
	set_skill("xiaoyaoyou", 25); 
	set_skill("parry", 25); 
	
	map_skill("force", "huntian-qigong");
	map_skill("hand", "shexing-diaoshou");
	map_skill("dodge", "xiaoyaoyou");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("ؤ��", 19, "����");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(1);
	carry_object("/d/gaibang/obj/budai")->wear();
}

string ask_me(string name, object ob)
{
	if ( name == "yaoyan" )
		return "���ϰ����������ݣ���˵�����һ��ظ����ղ˳ԡ�";

	if ( name == "zhulin" )
		return "��Ƭ���ֿ�����ؤ��ĵ��̡������������������ϰ�����ЩС�ˡ�������æ��";

	if ( name == "hong" )
		return "���ϰ�������̰�ԡ���������߶�Ż��غ����յĲˣ�˵���ػ��ա�
С�л��ֵ�����˵˭Ҫ���˺�������ԵĲˣ������ܾͻ�ָ��Щ�书�����п�����Ϊͽ�ܣ�
С�л�̾�˿���˵�����������������˺ü����µĲ��ˣ��ɺ��������û����Щɶ��";

	if ( name == "cook" )
		return "����ղ��𣿰���һ�°ɡ�����ȥ�Һò��ϣ��������գ�cook�������������������С�";

	if ( name == "beef" )
		return "���ظ����ϰ����չ�ţ������˵��ʲô���˭������÷����˵���������������ء�";

	if ( name == "soup" )
		return "�������������ϰ����������˵���ú�Ҷ������ӣ��ɶ���յģ��óԼ��ˡ�";

        if ( name == "baicai" )
		return "���ײ�˭���������������ϰ���˵�����س��ľͲ�ͬһ�㣬����Ѽ�ƺͼ��͡�";

	if ( name == "doufu" ) 
		return "����������������������˵��ʲô��ʮ��������ҹ����֪����ɶ�ر�ġ�";
	
}

