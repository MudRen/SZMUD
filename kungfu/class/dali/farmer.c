// Code of ShenZhou
// farmer.c ũ��
// A.P.

inherit NPC;

int do_push(string);

void create()
{
        set_name("����ͨ", ({ "wu santong", "nong", "farmer", "wu" }));
        set("long", 
			"һ������ũ��\n");
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 25);
        set("dex", 30);
        set("shen", 0);
        
        set("max_qi", 2000);   
       set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 120);
//        set("combat_exp", 350000);
        set("score", 5000);

        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("axe", 160);
        set_skill("finger", 130);
        set_skill("yiyang-zhi", 120);
        set_skill("duanshi-shenfa", 100);
        set_skill("kurong-changong", 80);

        map_skill("dodge", "duanshi-shenfa");
        map_skill("force", "kurong-changong");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger", "yiyang-zhi");

        set("inquiry", ([
	"��ɽ" : "ʲô��ɽ��ɽ��û�����Ҷ���ͦ��ס���𣿣�\n",
        ]));

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_push", "push");
}

int do_push(string arg)
{
	object me;
	me=this_player();

	if (arg!="rock") { return 0; }
	if (environment(me)!=find_object("/d/dali/yideng5.c")) { return 0; }
	if (me->query_str()>25 && (int)me->query("max_neili")>=1000) {
		write("���һ�������壬��ס���������㣡����\n");
		write("��ʹ��ȫ��������˫�����ƣ���ũ�򽫴�ʯ����������ߣ�\n");
		write("ũ������һ�Σ����ڴ�ʯ֮�⣬ȴ��ȥǣţ����һ˫���۽������²�ͣ�ش�����\n\n");
		me->move("/d/dali/yideng6.c");
		return 1;
	}

	write("����ͼ������ũ���ƿ���ʯ��������Ȼ������������������ҲûЧ����\n");
	return 1;
}
