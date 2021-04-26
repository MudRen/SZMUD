// Code of ShenZhou
// maskman.c ������

inherit NPC;

void create()
{
	int level;

	seteuid(getuid());
	set_name("���������ʿ", ({ "rysj weishi","weishi","shi" }) );
	set("gender", "����");
	set("age", 25+random(25));
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("str", 25);
	set("long",
		"��һ�ڽ����棬�ؿ����л����ǣ�˫������ɱ����ʱ��ʱ�ͳ�����Ц��\n");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "heroism");

	setup();

	level = 150 + (-1)^random(2) * random(100);
	if ( level < 100 ) level = 100;

	set("combat_exp", level*level*level/10);

	switch( random(4) )
                {
                case 0:
                       set_skill("cuff", level);
                       set_skill("yujiamu-quan", level);
                       map_skill("cuff", "yujiamu-quan");
                       prepare_skill("cuff", "yujiamu-quan");
                       set_skill("hand", level);
                       set_skill("dashou-yin", level);
                       map_skill("hand", "dashou-yin");
                       prepare_skill("hand", "dashouyin");
		       set_skill("force", level);		
                       set_skill("longxiang-banruo", level);                                set_skill("longxiang-banruo", level);
                       map_skill("force", "longxiang-banruo");
		       set_skill("dodge", level);
                       set_skill("shenkongxing", level);
                       map_skill("dodge", "shenkongxing");
		       set_skill("parry", level);	
                       switch( random(2) ) {
                          case 0:
                               set_skill("staff", level);
                               set_skill("jingang-chu", level);
                               map_skill("staff", "jingang-chu");
                               map_skill("parry", "jingang-chu");
                               carry_object("/clone/weapon/tiezhang")->wield();
                               break;
                          case 1:
                               set_skill("sword", level);
                               set_skill("mingwang-jian", level);
                               map_skill("sword", "mingwang-jian");
                               map_skill("parry", "mingwang-jian");
                               carry_object("/clone/weapon/changjian")->wield();
                               break;
			}
                	break;

                case 1:
                        set_skill("strike", level);
                      	set_skill("chousui-zhang", level);
                        map_skill("strike", "xingxiu-duzhang");
                        prepare_skill("strike", "xingxiu-duzhang");
                        set_skill("claw", level);
                        set_skill("sanyin-zhua", level);
                        map_skill("claw", "sanyin-zhua");
                        prepare_skill("claw", "sanyin-zhua");
                        set_skill("huagong-dafa", level);
			set_skill("force", level);
                        map_skill("force", "huagong-dafa");
                        set_skill("staff", level);
                        set_skill("tianshan-zhang", level);
                        map_skill("staff", "tianshan-zhang");
			set_skill("dodge", level);
                        set_skill("zhaixinggong", level);
                        map_skill("dodge", "zhaixinggong");
			set_skill("parry", level);
                        map_skill("parry", "tianshan-zhang");
                        carry_object("/clone/weapon/tiezhang")->wield();
                        break;

                case 2:
                        set_skill("strike", level);
                        set_skill("strike", level);
                        set_skill("lingshe-shenfa", level);
		        set_skill("dodge", level);
                        map_skill("dodge", "lingshe-shenfa");
                        set_skill("huagu-mianzhang", level);
                        map_skill("strike", "huagu-mianzhang");
                        prepare_skill("strike", "huagu-mianzhang");
                        set_skill("kick", level);
                        set_skill("jueming-tui", level);
                        map_skill("kick", "jueming-tui");
                        prepare_skill("kick", "jueming-tui");
			set_skill("force", level);
                        set_skill("dulong-dafa", level);
                        map_skill("force", "dulong-dafa");
                        set_skill("ruyi-gou", level);
                        map_skill("hook", "ruyi-gou");
                        set_skill("hook", level);
                        carry_object("/clone/weapon/hook")->wield();
                        break;

                case 3: 
                        set_skill("strike", level);
                        set_skill("hamagong", level);
                        set_skill("hand", level);
                        set_skill("shexing-diaoshou", level);
                        map_skill("hand", "shexing-diaoshou");
                        if ( level > 100 ) {
                                map_skill("strike", "hamagong");
                                prepare_skill("strike", "hamagong");
                        }
                        else {
                                prepare_skill("hand", "shexing-diaoshou");
                        }
			set_skill("force", level);
                        map_skill("force", "hamagong");
                        set_skill("staff", level);
                        set_skill("lingshe-zhang", level);
                        map_skill("staff", "lingshe-zhang");
			set_skill("parry", level);
                        map_skill("parry", "lingshe-zhang");
			set_skill("dodge", level);
                        set_skill("chanchubu", level);
                        map_skill("dodge", "chanchubu");
                        carry_object("/clone/weapon/tiezhang")->wield();
                        break;
                }

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		"����ʹ�ߴ���˵�������һͳ����ָ�տɴ�����ɱ�ʶʱ�񣬵�ʱ���Ī����\n",
		"����ʹ����Ц˵������̶������������޵У����ֱ���ű۵�������ȡ������\n",
		"����ʹ�ߵͳ�˵������̶���������ǧ�ŵ�һ�ˣ�ʶ��ĸϿ������Ͷ�ϣ�\n",
		"����ʹ�߸����ź����ճ�������Ψ�Ҳ��ܡ��ĳ���¡��󱻲�����\n",
		"����ʹ�߸����ź�������ʥ�𡢹�ҫ���ݡ�һͳ���������¹�ϣ�\n",
	}) );

	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", random(10));
}
