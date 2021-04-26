// Code of ShenZhou
void dest_bug(object bug);
void setup_npc(object me, object ob);

void init()
{
        add_action("do_search", "search");
	add_action("do_search", "zhao");
}	

int do_search(string arg) {
		

	string* n= ({
		"/d/xingxiu/forest10",
        	"/d/xingxiu/forest2",
        	"/d/xingxiu/forest3",
        	"/d/xingxiu/forest11",
        	"/d/xingxiu/forest4",
        	"/d/xingxiu/forest5",
        	"/d/xingxiu/forest1",
        	"/d/xingxiu/forest12",
        	"/d/xingxiu/forest6",
        	"/d/xingxiu/forest7",
        	"/d/xingxiu/forest8",
        	"/d/xingxiu/forest9",
        });

	object bug, me, fighter, room, gold, ob;

	int kar1, kar2, kar3, pot, max_pot, damage, find;	

	me=this_player();

	if( !arg || arg=="" ) return 0;
	
	if( arg=="bug" || arg=="chong"){

		if (!present("wa guan", me) && me->query("id")!="wsky")
                        return notify_fail("���ҵ�������ʲô��ʢ�أ�\n\n");
                        
                if (me->query("jingli")<me->query("max_jingli")/5)
                        return notify_fail("������Ϣһ�°ɡ�\n\n");
                        
		if (me->is_busy()) return
                        notify_fail("����һ��������û����ɡ�\n"); 
                        
		if (me->is_fighting()) return
                        notify_fail("���Ȱɵ�����������˵�ɡ�:)\n");
                        
		if (me->query_temp("found")==1) return
                        notify_fail("������Ȼ�ȥ�������������ɵȼ��ˡ�\n");
                                       
                //if (me->query_temp("bug_out")==1)
                //        return notify_fail("�����Ѿ������ˣ��Ͽ�ץ�ɣ�\n");
                
                if (me->query_temp("xx_job")!=1)
                        return notify_fail("������ʲô�ã�\n");
                
		me->add("jingli",-10);
		me->add("jing",-10);
		me->start_busy(random(1)+1);
		
		me->add("find_bug",1);
		me->add_temp("xx/find",1);

                message_vision("$N�������������ֽ���֦��Ҷ��������ϸѰ�Ҷ�����ټ���\n",me);
		
		kar2=(me->query("int")+me->query("con")+me->query("str"))*(random(2)+1);
		kar1=me->query_kar();		

		if (me->query("find_bug")>random(20)) {
			me->set("find_bug",0);
                                
			room = load_object(n[random(sizeof(n))]);
                        
                        message_vision("$N�������ң�����û��˿��������ټ���ֻ���뿪�������ĵط�Ѱ�ҡ�\n",me);
			message_vision("$N����ææ���뿪�ˡ�\n",me);
			me->move(room);
			message_vision("$N���˹�����\n",me);			
			return 1;
		}
		
		kar3=random(kar1*3);
		find=me->query_temp("xx/find");
		
		if (wizardp(me)) {
				printf("my kar=%d  kar=%d  randkar=%d  time: %d\n", kar1, kar3, kar2, find);
		}
		
		if ((kar3>kar2 && find>10) || (find>=30)) {

                        message_vision(HIG"ͻȻ��һֻС�������˳�����Ѹ�ٵ������š�\n"NOR, me);
                        bug=new("/d/xingxiu/npc/duchong");
			bug->move(environment(me));
			bug->set("playerid",me->query("id"));
                        me->set_temp("bug_out",1);
			me->set_temp("xx/find", 0);
			
			if (wizardp(me)) {
				printf("player id: %s \n", bug->query("playerid"));
			}
						
			return 1;
			
 		}
		
                   if (random(50)<=3 && (me->query("combat_exp")>=150000) && me->query_temp("xx_job")) { 

                        message_vision(HIR"ͻȻ�������Խ��һ���ˣ��ߺ�һ���������޼��ˣ�����������\n"NOR,me);
			fighter=new("/d/xingxiu/npc/xxnpc");
			setup_npc(me, fighter);
			fighter->set("player",me->query("id"));
			fighter->move(environment(me));
			fighter->kill_ob(me);
			//fighter->set_busy(random(2));			
			return 1;
		}
		
		
		if (random(kar1*3)<1){
			message_vision(HIW"$N��ǰ����һ�����ۣ����ӣ�\n"NOR,me);
			gold=new("/clone/money/silver");
			gold->move(environment(me));
			return 1;
		}
		
		if (random(kar1*2)<1){
			message_vision(YEL"$N��ǰͭ��һ�����ۣ�ͭǮ :(\n"NOR,me);
			gold=new("/clone/money/coin");
			gold->move(environment(me));
			return 1;
		}
		
		if (random(kar1*4)<1){
			message_vision(HIY"$N��ǰ���һ�����ۣ����ӣ�\n"NOR,me);
			message_vision(HIR"$N�������ӣ�����һ���⣬�����߹޵������ϴ�ķ��顣\n"NOR,me);
			gold=new("/clone/money/gold");
			gold->move(environment(me));
			ob = present("wa guan", me);
                        if(ob)destruct(ob);
			return 1;
		}
		
		if (random(20)<1){
			message_vision(MAG"\n$N��ѽһ���������ϵ�ʯͷ����һ����\n"NOR,me);
			me->start_busy(random(3)+2);
			damage=me->query_skill("force",1);
			me->receive_wound("qi", random(damage/10),"��ʯͷ����һ����ˤ����");
		}

                
		
        return 1;        
	} else if(arg=="dochong"){
		
		me->set_temp("fresh",1);
		message_vision("$N�������������ֽ���֦��Ҷ��������ϸѰ�Ҷ�����ټ���\n",me);
		
		if (me->query("find_bug")>random(20)) {
			me->set("find_bug",0);
                                
			room = load_object(n[random(sizeof(n))]);
                        
                        message_vision("$N�������ң�����û��˿��������ټ���ֻ���뿪�������ĵط�Ѱ�ҡ�\n",me);
			message_vision("$N����ææ���뿪�ˡ�\n",me);
			me->move(room);
			message_vision("$N���˹�����\n",me);			
			return 1;
		}
		
		
		return 1;
	}	
	
}


void setup_npc(object me, object ob){

		int skill, exp;

		exp=me->query("combat_exp");
		skill=me->query_skill("dodge",1);
	
		while(skill*skill*skill<exp*10) skill++;
		
		skill=skill/5*4;
		
		ob->set("xxtarget",me->query("id"));
		ob->set("combat_exp",exp*3/2);
		ob->set("max_qi", me->query("max_qi"));
	        ob->set("eff_qi", me->query("max_qi"));
        	ob->set("qi", me->query("max_qi"));
	        ob->set("max_jing", me->query("max_jing"));
        	ob->set("jing", me->query("max_jing"));
	        ob->set("eff_jing", me->query("max_jing"));
        	ob->set("neili", me->query("max_neili"));
	        ob->set("max_neili", me->query("max_neili"));
        	ob->set("jingli",me->query("jingli"));
	        ob->set("max_jingli",me->query("max_jingli"));
        	
        	if(me->query("combat_exp")>300000) ob->set("jiali", 50);
		if(me->query("combat_exp")>1000000) ob->set("jiali", 100);

	        if(ob->query("menpai")=="huashan") {
        	        
                	ob->set_skill("sword", skill);
	                ob->set_skill("huashan-jianfa", skill);
        	        ob->set_skill("parry", skill);
                	ob->set_skill("force", skill);
	                ob->set_skill("zixia-gong",skill);
        	        ob->set_skill("huashan-shenfa",skill);
                	ob->set_skill("hunyuan-zhang",skill);
	                ob->set_skill("dodge",skill);
        	        ob->set_skill("strike",skill);
                	ob->set_skill("cuff",skill);
	                ob->set_skill("pishi-poyu",skill);
   
   	                ob->map_skill("strike", "hunyuan-zhang");
        	        ob->map_skill("force", "zixia-gong");
	                ob->map_skill("parry", "huashan-jianfa");
        	        ob->map_skill("sword", "huashan-jianfa");
                	ob->map_skill("dodge", "huashan-shenfa");
	                ob->map_skill("cuff", "pishi-poyu");
        	
                	ob->prepare_skill("cuff","pishi-poyu");
	                ob->prepare_skill("strike","hunyuan-zhang");

			//ob->carry_object("/clone/weapon/gangjian")->wield();

	        }       else if(ob->query("menpai")=="shaolin"
        	) {
                	ob->set_skill("dodge", skill);
	                ob->set_skill("shaolin-shenfa", skill);
        	        ob->set_skill("cuff", skill);
                	ob->set_skill("jingang-quan", skill);
	                ob->set_skill("club", skill);
        	        ob->set_skill("zui-gun", skill);
                	ob->set_skill("strike", skill);
	                ob->set_skill("sanhua-zhang", skill);
        	        ob->set_skill("finger", skill);
                	ob->set_skill("nianhua-zhi", skill);
	                ob->set_skill("parry", skill);
        	        ob->set_skill("buddhism", skill);
                	ob->set_skill("literate", skill);
	                ob->set_skill("whip",skill);
        	        ob->set_skill("riyue-bian",skill);
                	ob->set_skill("yizhi-chan",skill);
	                ob->set_skill("banruo-zhang",skill);
			ob->set_skill("force",skill);
	
	                ob->map_skill("force", "hunyuan-yiqi");
        	        ob->map_skill("dodge", "shaolin-shenfa");
                	ob->map_skill("club", "zui-gun");
	                ob->map_skill("sword", "damo-jian");
        	        ob->map_skill("finger", "yizhi-chan");
	                ob->map_skill("strike", "banruo-zhang");
        	        ob->map_skill("claw", "longzhua-gong");
	                ob->map_skill("parry", "yizhi-chan");
        	        ob->map_skill("whip", "riyue-bian");
                	ob->map_skill("cuff", "jingang-quan");

	                ob->prepare_skill("finger", "yizhi-chan");
        	        ob->prepare_skill("strike", "banruo-zhang");
                	// ob->carry_object("/clone/weapon/tiegun")->wield();              
        
        	}       else if(ob->query("menpai")=="quanzhen"){
                	ob->set_skill("force", skill);
	                ob->set_skill("xiantian-gong", skill);
        	        ob->set_skill("dodge", skill);
                	ob->set_skill("jinyangong", skill);
	                ob->set_skill("cuff", skill);
        	        ob->set_skill("chunyang-quan", skill);
                	ob->set_skill("strike", skill);
	                ob->set_skill("sanhua-juding", skill);
        	        ob->set_skill("parry", skill);
                	ob->set_skill("sword", skill);
	                ob->set_skill("quanzhen-jian", skill);
        	        ob->set_skill("whip", skill);
                	ob->set_skill("duanyun-bian", skill);
	                ob->set_skill("literate", skill);
        	        ob->set_skill("taoism", skill);
                	ob->map_skill("force", "xiantian-gong");
	                ob->map_skill("dodge", "jinyangong");
        	        ob->map_skill("cuff", "chunyang-quan");
                	ob->map_skill("strike", "sanhua-juding");
	                ob->map_skill("parry", "quanzhen-jian");
        	        ob->map_skill("sword", "quanzhen-jian");
	                ob->map_skill("whip", "duanyun-bian");
	
        	        ob->prepare_skill("cuff", "chunyang-quan");
                	ob->prepare_skill("strike", "sanhua-juding");
                

			ob->carry_object("/d/jiaxing/obj/fuchen.c")->wield();
		}	else if(ob->query("menpai")=="emei"){
                	ob->set_skill("force", skill);
	                ob->set_skill("linji-zhuang", skill);
        	        ob->set_skill("dodge", skill*3/2);
                	ob->set_skill("zhutian-bu", skill);
	                ob->set_skill("tiangang-zhi", skill*3/2);
        	        ob->set_skill("finger", skill);
                	ob->set_skill("strike", skill);
	                ob->set_skill("jinding-zhang", skill);
        	        ob->set_skill("parry", skill);
                	ob->set_skill("blade", skill);
	                ob->set_skill("yanxing-dao", skill);
	                ob->set_skill("sword" , skill);
	                ob->set_skill("emei-jian" , skill);
        	        ob->map_skill("force", "linji-zhuang");
	                ob->map_skill("dodge", "zhutian-bu");
        	        ob->map_skill("finger", "tiangang-zhi");
                	ob->map_skill("strike", "jinding-zhang");
	                ob->map_skill("parry", "yanxing-dao");
        	        ob->map_skill("blade", "yanxing-dao");
        	        ob->map_skill("sword", "emei-jian");
	                	
        	        ob->prepare_skill("finger", "tiangang-zhi");
                	ob->prepare_skill("strike", "jinding-zhang");
                

			ob->carry_object("/clone/weapon/gangjian.c")->wield();
		} else if (ob->query("menpai")=="wudang"){
			ob->set_skill("force", skill);
	                ob->set_skill("taiji-shengong", skill);
        	        ob->set_skill("dodge", skill*3/2);
                	ob->set_skill("tiyunzong", skill);
	                ob->set_skill("taiji-quan", skill);
        	        ob->set_skill("cuff", skill);
                	ob->set_skill("taoism", skill);
	                ob->set_skill("parry", skill);
                	ob->set_skill("sword", skill);
	                ob->set_skill("taiji-jian", skill);
        	        ob->map_skill("force", "taiji-shengong");
	                ob->map_skill("dodge", "tiyunzong");
	                ob->map_skill("parry", "taiji-jian");
        	        ob->map_skill("sword", "taiji-jian");
			ob->map_skill("cuff", "taiji-quan");
	                	
        	        ob->prepare_skill("cuff", "taiji-quan");
                	//ob->carry_object("/clone/weapon/gangjian.c")->wield();
                } else {
                	ob->set_skill("force", skill);
	                ob->set_skill("shenghuo-xuanming", skill);
	                ob->set_skill("huagong-dafa", skill);
        	        ob->set_skill("dodge", skill);
                	ob->set_skill("qingfu-shenfa", skill);
	                ob->set_skill("hanbing-mianzhang", skill);
        	        ob->set_skill("strike", skill);
	                ob->set_skill("parry", skill);
                	ob->set_skill("sword", skill);
	                ob->set_skill("xiaoyao-jianfa", skill);
	                
	                ob->map_skill("force", "shenghuo-xuanming");
        	        ob->map_skill("dodge", "qingfu-shenfa");
	                ob->map_skill("parry", "xiaoyao-jianfa");
        	        ob->map_skill("sword", "xiaoyao-jianfa");
			ob->map_skill("strike", "hanbing-mianzhang");
			
			ob->prepare_skill("strike", "hanbing-mianzhang");
			
	                ob->carry_object("/clone/weapon/gangjian.c")->wield();
		}
}
