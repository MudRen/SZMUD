// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("��һ��", ({ "feng yiming", "feng", "yiming" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", 
	"���Ƿ�ɽ���ϴ����������֮�ӡ�ֻ����������ݣ�����Ӣ��������"
	"�����书������\n");
        set("shen_type", -1);

        set("combat_exp", 20000);

        set("attitude", "heroism");
	set("inquiry", ([
            	"�η�ë" : "С�ӣ���������\n",
		"������" : "���ǼҸ���\n",
                "�廢��" : "���ǼҸ������ɡ�\n",
	]));

	set("max_neili",500);
	set("neili",500);
	set("jiali",50);
        set_skill("cuff", 30);
	set_skill("wuxing-quan", 30);
	set_skill("force",30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("blade", 30);
	set_skill("wuhu-duanmen", 30);
	set_skill("wuxingbu",70);

	map_skill("cuff", "wuxing-quan");
	map_skill("blade", "wuhu-duanmen");
	map_skill("dodge","wuxingbu");
        map_skill("parry","wuhu-duanmen");

	prepare_skill("cuff", "wuxing-quan");
        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
