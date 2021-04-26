// Code of ShenZhou
// daobaifeng.c ���׷�
// Acep, Mantian

inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
	set_name("���׷�", ({ "dao baifeng", "dao"}));
	set("long", 
"���Ǹ���ò������������ã��Ǹ�������Ů�ӣ�����Ӻ�����ʡ�\n�����Ǵ�����ʵ۶�����������ԭ����ˡ�\n�����ɷ�������մ���ǲݣ�һŭ֮���ܵ�������˼ҡ�");
	set("title","���������");
	set("nickname","����ɢ��");
	set("gender", "Ů��");
	set("age", 35);
	
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 50);
	set("combat_exp", 300000);

	set("attitude", "peaceful");
	set("shen_type", 1);
	
	set_skill("strike", 80);
	set_skill("qingyan-zhang", 80);
	set_skill("dodge", 80);
	set_skill("duanshi-shenfa", 80);
	set_skill("parry", 80);
	set_skill("force", 70);
	set_skill("buddhism", 80);
	set_skill("sword", 70);
	set_skill("kurong-changong",70);
	set_skill("duanjia-jian", 70);
	set_skill("whip", 120);
	set_skill("feifeng-bian", 130);
	
	
	map_skill("dodge","duanshi-shenfa");
	map_skill("sword","duanjia-jian");
	map_skill("force","kurong-changong");
	map_skill("parry","duanjia-jian");
	map_skill("strike","qingyan-zhang");
	map_skill("whip","feifeng-bian");
	prepare_skill("strike","qingyan-zhang");
	
	set("inquiry", ([
		"�ɷ�޷�" 		:  (: ask_me :),
		"������"			: "���Ǹ���������ʲô��",
		"����"			: "�����Һþ�û������������",
		]));
        
	create_family("����μ�", 15, "����");
	setup();

	carry_object("/d/wudang/obj/greenrobe")->wear();	
	carry_object("/d/quanzhou/obj/fuchen")->wield();
}

void attempt_apprentice(object ob)
{
	string current_title;
	object me = this_player();
	current_title=ob->query("title");

	command ("look "+ob->query("id"));

        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="Ů��")
                        command ("say ʦ̫�Ƕ����ɵĸ��֣������Ƨ֮�粻�Ҷ�����");
                else
                        command ("say ��ʦ�������ɵĸ��֣������Ƨ֮�粻�Ҷ�����");
                return;
        }

        if( ob->query("family/family_name") == "ؤ��") {
                command ("say �������ǻ���֮�أ����ʼ�������ؤ�ɺ���ͳ��");
        	return;
        }
	
	if (ob->query("gender")!="Ů��") {
		command("shake "+ob->query("id"));
		command("say �㻹��ȥ��������Щ�ҳ�ѧ�հɡ�");
		return;
	}
	if (me->query("family/family_name")!="����μ�") {
		command("hmm "+ob->query("id"));
		command("say �㲻�Ǵ�����Ӱ����ܵ�����������ʲô��");
		return;
        }

	command("say �ðɣ��Ҿ��������ˣ�ϣ����ú�ѧ�գ���Ҫ����Щ���ı��ҵĳ������۸���");
	command("recruit " + ob->query("id"));
	ob->set("title", current_title);
	return;
}
string ask_me()
{
    object me=this_player();

	if (me->query("family/family_name")!="����μ�")	return RANK_D->query_respect(me)+"�Բ����㲻�Ǵ�����ӣ��ܵ�����������ʲô��\n";
	if (me->query("gender")!="Ů��") return "�Բ������޷��ش�������⡣\n";
	if (me->query_skill("feifeng-bian",1)) return "�㲻���Ѿ���������ô�������ң�\n";
	if (me->query("family/master_id") != "yideng dashi" && me->query("family/master_name") != "һ�ƴ�ʦ"){
		command("recruit " + me->query("id"));
		return "�ðɣ��Ҿ��������ˣ�ϣ����ú�ѧ�գ���Ҫ����Щ���ı��ҵĳ������۸���\n";
		}
	add_action("do_qingjiao", "qingjiao");
	command("consider");
	return "�ɷ�޷���һ���������޷�����Ȼ����ô���ģ��Ҿ�ָ����һ�°ɡ�\n";
}

int do_qingjiao(string arg)
{
	object obj=this_object(), me=this_player();
	int skill, myint;

	if (!arg) return notify_fail("�����򵶰׷����ʲô����\n");
	if (me->is_busy()) return notify_fail("��������æ���ء�\n");
	if (me->is_fighting()) return notify_fail("����ĥǹ������������\n");
	if (obj->is_fighting() || obj->is_busy()) return notify_fail("����æ���أ�û������㡣\n");
	if (!living(obj)) return notify_fail("�� ... ����Ȱ���Ū����˵��\n");
	if (arg!="feifeng-bian") return notify_fail("���׷�����������Ź����޷�ָ���㡣\n");
	if ((int)me->query("jing") <500 ) return notify_fail("�����������޷���̵��׷��κζ�����\n");
	if ((int)obj->query("jing") <100 ) return notify_fail("���׷�̫���ˣ��޷�ָ���㡣\n");

	message_vision("$N��$n��̷ɷ�޷����ƺ���������\n", me, obj);
    remove_action("do_qingjiao", "qingjiao"); 
	me->set_skill("feifeng-bian", 1);
	me->receive_damage("jing", 400);
	return 1;
}
