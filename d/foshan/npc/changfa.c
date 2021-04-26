// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("�ݳ���", ({ "qi changfa", "qi", "changfa" }) );
        set("gender", "����" );
	set("nickname","�����Ὥ");
        set("age", 48);
        set("long", 
	     "һ����ͷ��������ҧ��һ���̶̵ĺ��̴������д��Ų�Ь��ż��̧��ͷ����"
             "������������Ů������һ�ۡ����������⴩�������������һ��������"
	     "����������ͷ�׷�����������֮�ϡ�����������������������"
	     "Ƴ��һ��֮ʱ��������⾼Ȼ������������\n");
        set("shen_type", 0);

        set("combat_exp", 90000);

        set("attitude", "friendly");
	set("inquiry", ([
            	"�����Ὥ" : "�����ϵ�������������ºţ���˵�ҳ��ڷ��ء�\n",
		"���ǽ���" : "���ǽ�����Ҳ���ᣬ�����ҵ���ʬ����Ҳ��������\n",
                "���ǽ�" : "���ǽ�����Ҳ���ᣬ�����ҵ���ʬ����Ҳ��������\n",
		"��ʫѡ��" : "�Ҳ�ʶ�֣��Ӳ���ʫ��\n",
                "��ʬ����" : "�ҵ����׽���һ�����õ��˱��ʬ�����£�������ɡ�\n",
		"�ɻ�" : "��ȥ�ҷ���Ĳ�԰���ҽ��ʰѡ�\n",
		"����" : "��ȥ�ҷ���Ĳ�԰���ҽ��ʰѡ�\n",
		"�ݷ�" : "����СŮ����������Ҹ��ż���\n",
	]));

	set("max_neili",1000);
	set("neili",1000);
	set("jiali",50);
        set_skill("strike", 60);
	set_skill("force",60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("sword", 60);
	set_skill("tangshi-jian",60);
	map_skill("sword","tangshi-jian");
        map_skill("parry","tangshi-jian");
	set_skill("club",60);

        create_family("������", 5, "����");


        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/yanguan")->wield();
}

void attempt_apprentice(object ob)
{
        command("shake");
	command("say ��ʦ�Ͳ����ˡ������пհ��Ҹɵ���ӻ�Ҿͽ������ա�");
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("qi/work")){
		tell_object(ob, "�ݳ���˵���㻹���Ȱ��Ҹɵ����ɡ�");
                return 0;
	} 
        ob->add_temp("qi/work", -1);
        return 1;
}

