// Code of ShenZhou
// ½�˷� test job��
// mantian //add more path and make job counter may/11/2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

#include "/d/REGIONS.h";

int ask_xfsy();
string ask_me();
string ask_me_2(string name);
int ask_yapu();
int ask_abandon();
void create()
{
	set_name("½�˷�", ({ "lu chengfeng", "lu" }));
	set("title", "����ׯ��");
	set("long",
		"���ǻ�ҩʦ���ĵ���½�˷磬����ɫ���ݣ��ƺ����岻��ã�\n"
		"��˫�����вм���һֱ�������ϣ���������ߣ���������Ҳ��\n"
		"���˲��ߡ������һ��������Ⱦ����Ŷݼס�\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 200000);
	set("shen", 0);

	set_skill("force", 150);
	set_skill("bitao-xuangong", 150);
	set_skill("dodge", 120);
	set_skill("luoying-shenfa", 120);
	set_skill("strike", 120);
	set_skill("luoying-shenjian", 120);
	set_skill("qimen-dunjia", 120);
	set_skill("hand", 120);
	set_skill("lanhua-fuxue", 120);
	set_skill("whip",120);
	set_skill("canglang-bian", 120);
	set_skill("literate", 80);
	set_skill("parry", 120);	

	map_skill("force", "bitao-xuangong");
	map_skill("dodge", "luoying-shenfa");
	map_skill("strike", "luoying-shenjian");
	map_skill("parry", "luoying-shenjian");
	map_skill("hand", "lanhua-fuxue");

	prepare_skill("strike", "luoying-shenjian");

	create_family("�һ���", 2, "����");
	set("bagua_count", 5);
	call_out( "refresh_bagua", 1200 );
	set("yulu_count", 5);
	set("inquiry", ([
		"÷����" :"�������ﺦ���Һÿࡣ����Ҫ��͵������Ҳ���ˣ�����Ҫ͵ʦ���ġ������澭����",
		"������" :"����÷���綼��ʦ����ͽ���кκ�˵�������˺����Һÿ࣡�Ұ����죬���ǰ���������֮�͡�",
		"�����" :"���ʦ��ר���似����������һŮ����֪���������Σ�",
		"��Ĭ��":"��ɳ��һ���������ǰ��Ѱ��Ĭ�磬��ʦ�����Ե�����������ڸգ��������÷ǳ��ֶβ��ܱ�����¶��ݣ�����",
		"��ҩʦ" : "����ʦ��һŭ֮�£�������ʦ�ֵ�����һ����ϽŽ����һ�����",
		"�һ���" : (: ask_me :),
		"�Ż���¶��" : (: ask_me_2, "yulu-wan" :),
		"����ɨҶ���ķ�" : (:ask_xfsy:),
		"����" : (:ask_yapu:),
		"����" : (:ask_abandon:),
		"yapu" : (:ask_yapu:),
		"abandon" : (:ask_abandon:),
	]));
	setup();
	carry_object("/d/xixia/obj/robe")->wear();
}

void init()
{
	::init();
	add_action("do_recite", "recite");
}

void attempt_apprentice(object me)
{
	if ((string)me->query("family/family_name") == "ؤ��" && me->query("rank") > 1 )
	{
		command("say "+RANK_D->query_respect(me)+"��ؤ����֣�ˡ�Ҳ������㡣");
		return;
	}
	if( me->query("family/family_name") == "�һ���"
		&& me->query("family/master_name") == "��ҩʦ" )
	{
		command ("say "+RANK_D->query_respect(me)+"�Ǳ��ɸ��֣��ҿɲ���������");
		return;
	}
	if (me->query("class") && (me->query("class") != "beggar" && me->query("class") != "officer") 
                || (me->query("family/family_name") != "�һ���" && me->query("combat_exp") >= 100000) )
	{
		command("say "+RANK_D->query_respect(me)+"��������ʿ���αػ�����ׯ�췹��\n");
		return;
	}       
	if( me->query_temp("pending/recite") )
	{
		command("say ��ֱɲ��ģ���ʶǳ������ׯ���������㣿");
		return;
	}
	else
	{
		command("say һλ�������ڱ�ׯ������ʫ���ڣ�������ܲ�ȫ��Ҳ����������ׯһ��");
		message_vision("½ׯ��������$N��˵�������������ڴ�������(recite)�����ɡ�\n",
		this_player());
		me->set_temp("pending/recite", 1);
	}
}

int do_recite(string arg)
{
	string name, new_name, ttt;
	if( !this_player()->query_temp("pending/recite") ) return 0;
	if( !arg ) return notify_fail("��˵ʲô��\n");
	this_player()->set_temp("pending/recite", 0);
	message_vision("$N����˵����" + arg + "\n", this_player());
	if( arg == "���������ɲ����º�ɳ")
	{
		command("smile");
		if (this_player()->query("gender") == "����") ttt = "����";
		else  if (this_player()->query("gender") == "Ů��") ttt = "����";
		else
		{
			command("sigh");
			command("say "+"�䱾���ˣ��κ��Թ�����ׯ�붫�����޹�������ȥ�ɣ�");
			return 0;
		}
		command("say "+"�ã��ã�"+RANK_D->query_respect(this_player())+"��Ȼ����ǿ�ǡ����˾���������" + ttt +"�ɡ�");
		command("recruit " + this_player()->query("id"));
		this_player()->set("title", "����ׯ" + ttt);
	}
	else
	{
		command("say ����׶����������û�������ҵ����ӣ�");
	}
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] !="�һ���")
		return RANK_D->query_respect(this_player()) +"���ׯ������������֪�˻��Ӻ�̸��";
	if (query("bagua_count") < 1)
		return "������̫���ˣ���ʲô��������˵�ɡ�";
	if (  present("tie bagua", this_player()) || this_player()->query_temp("get_bagua"))
		return "������������һ�����һ�ԣ�����û�и��ݼ�����ʦ����";
	if (this_player()->query_skill("qimen-dunjia", 1) < 60
		|| this_player()->query_skill("bitao-xuangong", 1) < 60)
		return "�һ����ϻ������أ��㹦�򲻹������ǲ�ȥΪ�";
	add("bagua_count", -1);
	ob = new("/d/taohua/obj/bagua");
	ob->move(this_player());
	this_player()->set_temp("get_bagua",1);
	message_vision("½�˷�ݸ�$Nһ�������ԡ�\n", this_player());
	return "�ϵ�֮��ǧ��С�ģ����¿��Լ�����Ҳ�ﲻ��ʲôæ�ˡ�";
}

string ask_me_2(string name)
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�һ���")
		return RANK_D->query_respect(this_player()) +"�뱾��������������֪�˻��Ӻ�̸��";

	if (this_player()->query("combat_exp") < 5000)
		return "�㹦�򲻹������ǲ�ҪΪ�";

	if (query("yulu_count") < 1)
		return "��Ǹ�������ò���ʱ���Ѿ������ˡ�";

	if (this_player()->query_condition("work") > 0)
		return "�Ҳ��ǲŸ�����ҩ����������Ҫ�ˣ�����̰�����ᣡ";
        if ( present( "yulu wan", this_player() ) )
                return "�㲻�ǻ���������̰�����ᣡ";

	ob = new(DRUG_D(name));
	ob->move(this_player());
	this_player()->apply_condition("work", 30);

	add("yulu_count", -1);
	message_vision("½�˷��$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�С�ı�Ū���ˡ�";
} 
/*
void unconcious() 
{
	message_vision("\nͻȻ��ֻ��$N������̫ʦ�η�����һ�ƣ�����ǽ��һ�����ѿ������˴��ζ��������ڣ�Ӱ�ٲ�����\n",this_object());
	destruct(this_object());
}
*/
int accept_kill(object me)
{
	if (me->query("family/family_name") == "�һ���")
	{
		command("say ���ұ���ͬ�ţ����Ҫ�Ӻ����ң�\n");
		me->set("th_killer", 1);
		kill_ob(me);
		return 1;
	}
	return 0;
}

int accept_object(object me, object obj)
{
	call_out("accept_obj", 2, me, obj);
	return 1;
}

int accept_obj(object me, object obj)
{
	if( obj->query("name") == "����ɨҶ���ķ�" )
	{
		command("ah");
		message_vision(CYN"$N˫�ֲ�����չ����ֽ������ϸϸ�Ķ���������\n",this_object());
		message_vision(CYN"$Nһ�߶���һ������ӯ����\n",this_object());
		command("cry");
		command("say ��л"+ RANK_D->query_respect(me) +"�ˡ�\n");
		set("xfsy_xinfa_reading",1);
		set("xfsy_xinfa_accept",1);
		if( me->query("family/family_name") == "�һ���" )
		me->set("help_chengfeng",1);
	}
	call_out("finish_reading", 100+random(50), obj);
	return 1;
}     

void finish_reading(object obj)
{
	delete("xfsy_xinfa_reading");
	destruct(obj);
}

int ask_xfsy()
{
	object me, obj;

	me = this_player();
	if( query("xfsy_xinfa_reading") )
	{
		command("say �Բ�ס���һ�û�����ʦ�����ķ���");
		return 1;
	}

	if( me->query("family/family_name") == "�һ���" 
		&& query("xfsy_xinfa_accept") )
	{
		obj = new("/d/taohua/obj/xfsy_xinfa2");
		obj->move(me);
		command("say �����ķ�������һЩע�⣬"+RANK_D->query_respect(me)+"���û�ȥ���в���");
		message_vision("$N�ݸ�$nһ�ű�ֽ��\n",this_object(),me);
		delete("xfsy_xinfa_accept");
	}
	else command("say ����ɨҶ���ķ��Ѳ��������");
	return 1;
}

int ask_yapu()
{
	string* yapu_room = ({
		"/d/hangzhou/yuhuang"+(1+random(3)),
		"/d/hangzhou/road41",
		"/d/hangzhou/road"+(63+random(4)),
		"/d/hangzhou/road78",
		"/d/hangzhou/lingyin0",
		"/d/hangzhou/suti"+(1+random(7)),
		"/d/hangzhou/kedian",
		"/d/foshan/street"+(1+random(4)),
		"/d/foshan/qzroad"+(1+random(7)),
		"/d/foshan/dlroad"+(1+random(7)),
		"/d/foshan/beidi",
		"/d/foshan/cunkou",
		"/d/foshan/road"+(1+random(4)),
		"/d/quanzhou/zhongxin",
		"/d/quanzhou/xiqiao",
		"/d/quanzhou/yaopu",
		"/d/quanzhou/tumen",
		"/d/quanzhou/shijiefu",
		"/d/quanzhou/yongning",
		"/d/quanzhou/gangkou2",
		"/d/quanzhou/tudi",
		"/d/quanzhou/shanlu"+(1+random(6)),
		"/d/quanzhou/enyuan",
		"/d/huanghe/bank"+(1+random(8)),
		"/d/taishan/daizong",
		"/d/taishan/yitian",
		"/d/huanghe/bank7",


	});

	string region, id;	
	object me, ob, jiading, weapon, room; 
	int exp;
	mapping fam;

	me = this_player();
	exp = me->query("combat_exp");
	id = me->query("id");

	if (me->query("family/family_name") != "�һ���")
	{
		command("say �һ����ϵ����͸���������������ļ��֮ͽ���Ҷ�ʦ���Ȳ��ȷʵ����һһ�������ϣ����ƴ������Թ���ʹ��");
		return 1;
	}
	if(me->query("combat_exp") < 20000)
	{
		command("say ��Ҳ��׽�����᣿־���ɼΣ��������ǰѹ���������˵��");
		return 1;
	}
	
	if(me->query("id")!="maco" && base_name(environment(me)) != "/d/taihu/shufang")
	{
		command("en lu chengfeng");
		command("say �ȵ��һع���ׯ��˵��");
		message_vision("½�˷��������֣������Ҷ�̧����齹�������½�˷��������뿪�ˡ�\n",me);
		move("/d/taihu/shufang");
		message("vision", "½�˷���������ϣ��������Ҷ�̧�������鷿����\n", environment(this_object()),this_object());
		return 1;
	}

	if(me->query("th_yapu_ok"))
	{
		if(me->query("th_help_yapu"))
		{
			command("thumb " +me->query("id"));
			command("say �����ˣ�����ͬȥ�ļҶ��Ѿ����Ǹ�"+me->query("find_yapu")+"���˻�����");
			command("say �������˽����"+me->query("find_yapu")+"����ׯ������Ƿ��иĹ�֮�⣬���ж��ᡣ");
			me->delete("th_help_yapu");
		}
		else
		{
			command("applaud " +me->query("id"));
			command("say �����ˣ�����ͬȥ�ļҶ��Ѿ����Ǹ�"+me->query("find_yapu")+"���˻�����");
			command("say �һ����������һ���ȥ�����ɶ�ʦ���á�");
		}
		me->delete("find_yapu");
		me->delete("th_yapu_ok");
		me->delete("zangbu_yapu");
		me->delete("th_discuss"); //�ɼ���discuss
		me->add("th_yapu_job", 1);
		if (me->query("th_yapu_job") >= 5)
		{
			me->set("th_yapu_job",0);
			me->set("th_ask_drug",1);
		}
		me->apply_condition("th_yapu_job", 0);

		set("yapu_ok/"+id,1);
		add("yapu_enough/"+id,1);
		call_out("wait_job", 10, id);
		if (query("yapu_enough/"+id) >= 5)
		call_out("wait_job2", 10, id );

		return 1;
	}

	else if (query("yapu_ok/"+id))
	{
		command("say "+ RANK_D->query_respect(me) +"�Ÿոջ�����������������ЪϢ�ա�");
		return 1;
	}
	else if (query("yapu_enough/"+id) >= 5)
	{
		command("say ʱ������"+ RANK_D->query_respect(me) +"����ι����ȥ������"+ RANK_D->query_respect(me) +"�Ͳ���̫�������ˡ�");
		return 1;
	}
	else if ((int)me->query_condition("th_yapu_fail") > 0)
	{
		command("hmm " +me->query("id"));
		command("say "+ RANK_D->query_respect(me) +"������ЪЪ���ñ��˴������°ա�");
		return 1;
	}
	else if(me->query("find_yapu"))
	{
		command("say ��ǰ��"+me->query("find_yapu")+"�㻹û�ҵ��ɣ�");
		return 1;
	}
	else
	{
		ob = new("/d/taohua/npc/yapu_npc");
		jiading = new("/d/taohua/npc/jiading");
		room = load_object(yapu_room[random(sizeof(yapu_room))]);
		if ( strsrch(file_name(room), "/d/") != 0	
			||  undefinedp(region = region_names[explode(file_name(room), "/")[1]]))
		region = "";

		command("say ����и�"+ob->query("real_name")+"ʱ����"+region+"һ��Ϊ��");
		message_vision("½�˷��������֣�һ��ׯ���߽��˴�������$N���˸�Ҿ��\n",me);
		jiading->move(environment(me));
		command("say ������"+room->query("short")+CYN"���ִ������٣���������Ѱ����"+ob->name()+"��磬��ɴ������Ǹ������ҿ���"NOR);
		command("say Ҫ����ָ��(ren)�������Ͱ���"+ob->query("real_name")+"���£����ƴ��������һ�������Щ����һ�㴦��ա�");
		me->apply_condition("th_yapu_job", 10);
		me->set("zangbu_yapu",ob->query("id"));
		me->set("find_yapu",ob->query("real_name"));

		jiading->set("find_yapu",ob->query("name"));
		jiading->set("find_yapu_real",ob->query("real_name"));
		jiading->set_leader(me);
		jiading->set("job_master",me->query("id"));
		jiading->set("start",1);
		jiading->set("yapu_region",region);
		jiading->set("yapu_room",room->query("short"));
		jiading->start_check(me);
		me->set_temp("yapu", ob);
		me->set_temp("jiading",jiading);

		ob->move(room);
		ob->set("yapu_target",me->query("id"));
		message("vision", ob->query("name")+"�첽���˹�����\n", room, ob);
		ob->random_move();

		//moon is maco's dummy
		if( me->query("id") == "maco" || me->query("id") == "moon" )
		{
			tell_object(me,"����������"+base_name(room) +"\n");
			ob->move(environment(me));
		}
	return 1;
	}
}

int ask_abandon()
{
	object me, ob, jiading, weapon, room; 
	int exp;
	me = this_player();
	exp = me->query("combat_exp");
	if(!me->query("find_yapu"))
	{
		command("? " +me->query("id"));
		return 1;
	}
	else if(me->query("th_yapu_ok"))
	{
		command("haha " +me->query("id"));
		command("say "+ RANK_D->query_respect(me) +"˵Ц�ˣ���"+me->query("find_yapu")+"�Ѿ����������ˣ�������");
		return 1;
	}

	else if(me->query_condition("th_yapu_job") > 0)
	{
		command("hmm " +me->query("id"));
		command("say �Ÿո�Ҫ��ȥ׽��"+me->query("find_yapu")+"�������Ҫ������");
		return 1;
	}

	else
	{
		command("say ׽�����Ǹ�"+me->query("find_yapu")+"��");
		command("sigh " +me->query("id"));
		command("say ���ˣ�����Ϣһ�£���������������˴���ա�");
		me->delete("find_yapu");
		me->apply_condition("th_yapu_fail", 3 );
		return 1;
	}

}

void wait_job(string id)
{
	delete("yapu_ok/"+id);
}

void wait_job2(string id)
{
	delete("yapu_enough/"+id);
}

void refresh_bagua()
{
	set( "bagua_count",  2 );
	set( "yulu_count", 2 );
        call_out( "refresh_bagua", 1200 );
}
