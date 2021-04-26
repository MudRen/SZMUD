// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("������", ({ "feng tiannan", "feng", "tiannan" }) );
        set("gender", "����" );
	set("title","�廢��������");
	set("nickname","�ϰ���");
        set("age", 55);
        set("long", 
	"�����ϴ�������Ʋ����С�ڣ�ٲȻһ�������ŵĴ�����ģ����\n"
	"�����Ų����ȣ�˫Ŀ����������书��ǿ��\n");
        set("shen_type", -1);

        set("combat_exp", 250000);

        set("attitude", "heroism");
	set("inquiry", ([
            	"�η�ë" : "С�ӣ���������\n",
		"��һ��" : "����Ȯ�ӡ�\n",
                "�廢��" : "�����Ϸ�ȫ��һ����ͭ������������޵��֣��Ŵ������廢�š�\n",
	]));

	set("max_neili",1000);
	set("neili",1000);
	set("jiali",100);
        set_skill("cuff", 80);
	set_skill("wuxing-quan", 80);
	set_skill("force",80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("club", 80);
	set_skill("wuhu-gun",80);
	set_skill("wuxingbu",70);
	map_skill("club","wuhu-gun");
	map_skill("cuff", "wuxing-quan");
	map_skill("dodge","wuxingbu");
        map_skill("parry","wuhu-gun");

	prepare_skill("cuff", "wuxing-quan");
        create_family("�廢��", 1, "������");


        setup();
        carry_object("/d/dali/obj/zipao")->wear();
	carry_object("/clone/weapon/jingun")->wield();
}

void attempt_apprentice(object ob)
{
        command("shake");
	command("say ���������Ѿ����ˣ��Ϸ�����ͽ�����ˡ�");
}

void unconcious()
{
	object me = this_object();
	object ring;
        message_vision("\n$N��¶��Ц����Ȼ����һ�ѵ�����˵������һ������һ�˵�����ĳ�����ٻ��������С����������\n",
		me);
	message_vision("�ۿ�$N�����ᾱ����ҪѪ��������������ವ�һ����һ������"+
	"�ӵ��������������ѵ������ᡣ\n",me);
	message_vision("����һ���֮�ʣ�$N�˻������ˡ�\n",me);
	ring = new(__DIR__"obj/zhihuan");
	ring->move(environment(me));
        destruct(me);
}

void die()
{
        object me = this_object();
        object ring;
        message_vision("\n$N��¶��Ц����Ȼ����һ�ѵ�����˵������һ������һ�˵�����ĳ�����ٻ��������С����������\n",
                me);
        message_vision("�ۿ�$N�����ᾱ����ҪѪ��������������ವ�һ����һ������"+
        "�ӵ��������������ѵ������ᡣ\n",me);
        message_vision("����һ���֮�ʣ�$N�˻������ˡ�\n",me);
        ring = new(__DIR__"obj/zhihuan");
        ring->move(environment(me));
        destruct(me);

}

