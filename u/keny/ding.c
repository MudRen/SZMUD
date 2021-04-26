// Code of ShenZhou
// rama@sz modified
// ding.c ������
#include "/kungfu/class/xingxiu/auto_perform.h"
#define ANTI_ROBOT "/u/yeer/robot"
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void no_answer(object user);
string ask_me();
string ask_zhen();
int auto_perform();
int ask_ding();
int ask_book();
int ask_poison();
string ask_suo();
string ask_wxs();
int ask_staff();
int do_answer(string arg);
int ask_job();
int ask_chname();
void create()
{
        set_name("������", ({ "ding chunqiu", "ding" }));
        set("nickname", "�����Ϲ�");
        set("long",  "�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
                     "��������������ò���棬�ɷ���ǡ�\n");
        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 40);
        set("con", 35);
        set("dex", 35);
        
        set("max_qi", 4500);
        set("max_jing", 2500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);
        set("combat_exp", 3500000);
        set("shen", -400000);
        set("apply/armor", 50);
        set("PKS", 1000000);

        set_skill("force", 400);
        set_skill("huagong-dafa", 400);
        set_skill("dodge", 360);
        set_skill("zhaixinggong", 400);
        set_skill("strike", 360);
        set_skill("claw", 360);
        set_skill("sanyin-zhua", 360);
        set_skill("poison", 400);
        set_skill("chousui-zhang", 360);
        set_skill("parry", 360);
        set_skill("staff", 360);
        set_skill("tianshan-zhang", 400);
        set_skill("feixing-shu", 360);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("claw", "sanyin-zhua");
        map_skill("sword", "tianshan-zhang");

        prepare_skill("strike", "chousui-duzhang");
        prepare_skill("claw", "sanyin-zhua");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        create_family("������", 1, "��ɽ��ʦ");
        //set("class", "taoist");
        set("san_count", 3);
        set("suo_count",1);
        set("zhen_count", 7);
        set("wxs_count",3);
        set("inquiry", ([
                "��ң��Цɢ" : (: ask_me :),
                "������" : (: ask_zhen :),
                "��˿��" : (: ask_suo :),
		"����" : (: ask_job :),
		"job" : (: ask_job :),
		"����ɢ" : (: ask_wxs :),
		"������" : (: ask_staff :),
		"����" : (: ask_chname :),
		"���Ͼ綾" : (: ask_poison :),
		"�ⶾ" : (: ask_poison :),
		"book" : (: ask_book :),
		"�׽��ƪ" : (: ask_book :),
		"��ľ����" : (: ask_ding : ),
        ]));

        setup();
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/rousi-suo");
}


void init()
{
        object ob,ob1;
        string poison;
               
        ::init();
        add_action("do_answer", "answer", 1);
        if( interactive(ob=this_player()) && ob->query_condition("bingcan_posion") ) {
		   command("?" + ob->query("id"));
		   command("say" + ob->query("name") + "��ͽ��,���ƺ����˱��Ͼ綾��\n");
	   }
	
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "ding chunqiu"
        && ob->query("shen") > 100 && ob->query("id")!="wsky") {
                command("say " + RANK_D->query_rude(ob) + "���㵨����׵������£���Ȼ�ǲ�����������˰ɡ�\n");
                command( "expell " + ob->query("id"));
        }
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "ding chunqiu"
        && (!present("yu di", this_player()))){
                ob1=new("/d/xingxiu/obj/yudi");
                ob1->move(this_player());
                command("say ��ֻ������������޵��ӵĻ��������ú����ţ�����Ū����");
                write("���������һֻ��ѡ�\n");
        }
        add_action("do_flatter", "flatter");
}
int ask_book()
{
	object ob;
     object me=this_player();

       if(me->query("canbook")==1 && (!present("yijinjing", me)) ) {
		tell_object(me,"������˵��������ͽ������û��͸�Ȿ�׽�İ���ô��\n");
		tell_object(me,"�Ǻðɡ��Ȿ�������㣬�û�ȥ�úò���ɣ�\n");
		tell_object(me,"ͽ����һ��Ҫ��ס��ǧ�������ľ����һ��������Ҫ��Ȼ�������߻���ħ����\n");
                ob=new("/d/quest/xingxiu/obj/book2.c");

		ob->move(me);
		write("���������һ���׽��\n");
		return 1;
	}
	else
		return 0;
}
int ask_ding()
{	
	object ob;
	object me=this_player();
        if(me->query("ask/ding")==1 && (!present("shenmu wangding",me)) && me->query("family/master_id") == "ding chunqiu")
	{
		tell_object(me,"�ҿ���Ѱ���׽��������ľ�����ŵ���ʧ�����������Ȼ��Ҫ����ȥ�ɡ�\n");
                ob=new("/d/quest/xingxiu/obj/muding.c");

		ob->move(me);
		return 1;
	}
	else return 0;
	
}
	
int ask_poison()
{
	object ob=this_player();
	if(ob->query("family/master_id" )=="ding chunqiu" && ob->query_condition("bingcan_poison")) 
	{
	tell_object(ob,"Ҫ����Ͼ綾�����ְ취��������׽��ƪ��
	Ȼ�������ľ�������������󷨣���㶾�����ʲô��
	��ϧ�����Ǳ���ƪ������Ȼ���䲻������������ҵ���
	����Ļ����ҿ����Ժ��Ȼ���ֲ������󷨵�ȱ������
	��֮�⣬ֻ�ܿ�ҩ���ӹ��˽��ˣ�\n");
	return 1; }
	else
	return 0;
	
}	

int do_answer(string arg)
{
        int result;
        object me = this_object(), user = this_player();
        result = ANTI_ROBOT->do_answer(arg, user, me);

        if (result == 2) {
                command("whisper " + user->query("id") + " �ã��ã��ã��������ڷ����ˡ�");
                command("say " + user->name(1) + "������ʲô����ֻ�����Ұɣ�");
                user->set("passed_ding", 1);
                return 1;
        }

        if (result == -1) {
                command("hummer " + user->query("id"));
                command("say " + user->name(1) + "�������������Ȼ����ƭ���ɣ����ҹ�һ��ȥ��");
                user->add("ding_robot", 1);
                user->set("robot_ding", user->query("mud_age") + user->query("ding_robot")*600);
                return 1;
        }

        return result;
}

void no_answer(object user)
{
        if(objectp(present(user->query("id"), environment()))) {
        command("beep " + user->query("id"));
        command("heihei " + user->query("id"));
        command("say " + user->name(1) + "������Ϊ��װ���Ҿ��β���������");
        command("say ���ҹ�һ��ȥ�ɣ�");
        }
else {
        command("tell " + user->query("id") + " " + user->name(1) + "������Ϊ��װ���Ҿ��β���������");
        command("tell " + user->query("id") + "����ʱ�ò��Ÿ����������ˣ�");
}
        user->add("ding_robot", 1);
        user->set("robot_ding", user->query("mud_age") + user->query("ding_robot")*600);
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -100000) {
                command("say ����Խ����Խ��׵������Ե׵ġ�");
                return;
        }
        if( me->query("family/family_name") == "ؤ��"
        && me->query("combat_exp") >= 10000 ) {
                command ("say ������ƽ��޽л��ӣ�����ҹ���ԶԶ�ģ�");
                return;
        }
        if ((int)me->query_skill("poison", 1) < 50){
                command("say " + RANK_D->query_respect(me) +
                        "�Ķ�������ô���ȥ��ץ���������˵�ɡ�");
                return;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say ����˲������ɷ�����������������㣿");
                return;
        } else {
                command("say ���������ɱ������������ʥ����ô������");
                message_vision("�����Ϲ�΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        object ob;
        string name, new_name;
        mapping fam;
        int x;
        int contribution=this_player()->query("xingxiu/contribution");
        
        fam=this_player()->query("family");
        
        if (this_player()->query_temp("pending/flatter")){ 	                
        	if( !arg ) return notify_fail("��˵����ʲô��\n");
        	this_player()->set_temp("pending/flatter", 0);
        	message_vision("$N����˵����" + arg + "\n", this_player());
        	if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
	         	|| strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 )) {
                	command("smile");
                	this_player()->set("oldname", name);
                	name = this_player()->query("name");
                	x=random(3);
                	if (x==3)             	
                		new_name =  name[0..01] + name[2..3] + "��";
                	else if (x==2) 
                		new_name =  name[2..3] + name[0..01] +  "��";
                	else if (x==1)
                		new_name =  name[0..01]+ "��" + "��";
                	else 
                		new_name =  name[0..01]+ "��" + "��";
                	
                	command("say �⻹��࣬�ӽ��Ժ�������ֽ���" + new_name + "��");
                	this_player()->set("name", new_name);
                	command("recruit " + this_player()->query("id"));
		        if (!present("yu di", this_player())){
                		ob=new("/d/xingxiu/obj/yudi");
                		ob->move(this_player());
                		command("say ��ֻ������������޵��ӵĻ��������ú����ţ�����Ū����");
                		write("���������һֻ��ѡ�\n");
        		}
        	} else {
                	command("say ����˲������ɷ�����������������㣿");
        	}
        	return 1;
        } else if(fam["family_name"]=="������") {
		if(contribution<100){
			command("say ����쵰�����������ң�");
		} else if(contribution>100 && contribution<500) {
			command("say ͽ���ɵò����ٽ���ȥΪʦһ�����͡�");
		} else if(contribution>500) {
			command("say ��ͽ������������ʲô�������ĵط��������ҡ�");
			this_player()->set_temp("canask",1);
		}
		return 1;	
	}

	return 0;

        
        
}

int ask_chname(){
	
	object me=this_player();
	mapping fam;
	string name, new_name;
	int contribution=this_player()->query("xingxiu/contribution");
	int x;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("say ����Ҫ����Ц��");
		return 1;
	}
	
	if (contribution<100) {
		command("shake "+me->query("id"));
		command("say ������ɹ��ײ�����");
	} else {
		command("ok");
		name = this_player()->query("name");
                new_name=name;
                
                while(name==new_name) {
                
                x=random(6);
                
                if (x==6)             	
                	new_name =  name[0..01] + name[2..3] + "��";
                else if (x==2) 
                	new_name =  name[2..3] + name[0..01] + "��";
                else if (x==1)
                	new_name =  name[0..01]+ "��" +  "��";
                else if (x==3)
                	new_name =  name[0..01]+ "��" +  "��";
                else if (x==4)
                	new_name =  name[0..01]+ "Ե" +  "��";
                else if (x==5)
                	new_name =  name[0..01]+ "ڤ" +  "��";
                else 
                	new_name =  name[0..01]+ "��" +  "��";
                
	        }
        
                command("chat �ӽ��Ժ�"+name+"�����ֽ���" + new_name + "��");
                
                this_player()->set("oldname", name);
                this_player()->set("name", new_name);	
                this_player()->add("xingxiu/contribution", -50);	
	}

	return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
string ask_suo()
{
        mapping fam;
        object ob;
                
        if (!(fam = this_player()->query("family")) || fam["family_name"]!="������")
                return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("suo_count") < 1)
                return "�������ˣ�������ʦ���������ˡ�";
        if (  present("rousi suo", this_player()) )
                return "���Ǹո���������ô����Ҫ�ˣ�";
        if ( this_player()->query_skill("feixing-shu", 1) < 120)
                return "�ⶫ����ɲ����档";
        add("suo_count", -1);
        ob = new("/d/xingxiu/obj/rousi-suo");  
        ob->move(this_player());   
        say("���������һ����˿����\n");
        return "�ðɣ���ȥ�ú����á�����Ϊʦ������Ѫ���ã����Ҫ��ϧ��";
}

string ask_wxs()
{
        mapping fam;
        object ob;
                
        if (!(fam = this_player()->query("family")) ||fam["family_name"]!="������")
                return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("wxs_count") < 1)
                return "�������ˣ�������ʦ���������ˡ�";
        if (  present("wuxing san", this_player()) )
                return "���Ǹո���������ô����Ҫ�ˣ�";
        if ( this_player()->query_skill("feixing-shu", 1) < 120)
                return "�ⶫ����ɲ����档";
        add("wxs_count", -1);
        ob = new("/d/xingxiu/obj/wuxing");  
        ob->move(this_player());   
        say("���������һ������ɢ��\n");
        return "�ðɣ���ȥ�ú����á�����Ϊʦ������Ѫ���ã����Ҫ��ϧ��";
}


string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="������")
                return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("san_count") < 1)
                return "�������ˣ�������ʦ���������ˡ�";
        if (  present("sanxiao san", this_player()) )
                return "���Ǹո���������ô����Ҫ�ˣ�";
        if (this_player()->query_skill("poison", 1) < 100 ||
        this_player()->query_skill("feixing-shu", 1) < 100 ||
        this_player()->query_skill("huagong-dafa", 1) < 100)
                return "�ⶫ����ɲ����档";
        add("san_count", -1);
        ob = new("/d/xingxiu/obj/sanxiao");
        ob->move(this_player());
        say("���������һ����ң��Цɢ��\n");
        return "�ðɣ���ȥ�ú����á�";
}

string ask_zhen()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="������")
                return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("zhen_count") < 1)
                return "�������ˣ�������ʦ���������ˡ�";
        if (  present("bilin zhen", this_player()) )
                return "���Ǹո���������ô����Ҫ�ˣ�";
        if (this_player()->query_skill("poison", 1) < 50 ||
        this_player()->query_skill("feixing-shu", 1) < 50 ||
        this_player()->query_skill("huagong-dafa", 1) < 50)
                return "�ⶫ����ɲ����档";
        add("zhen_count", -1);
        ob = new("/d/xingxiu/obj/blzhen");
        ob->move(this_player());
        say("���������һ�ѱ����롣\n");
        return "�ðɣ�ȥ���Ҹɵ������׵������";
}


int ask_job(){
	
	object me=this_player();
	object waguan;
	mapping fam;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("?");
		return 0;
	}
		
        if (me->query("robot_ding") > me->query("mud_age")) {
                command("say �ߣ��ϴ���ƭ���ɵ��£����ɻ�û�к��������أ������ڻ������������ǣ�");
                command("say ���ȸ��һ�ȥ�ú÷�ʡ�Լ�һ�£��Ժ�������");
                return 1;
        }

        if(me->query("robot_answer")) return notify_fail("����Ϸ����ǰ��������ˣ�\n");

        if (random(4) == 1 && !me->query("passed_ding")) {
                command("say ��ҹ�Ϸ������˸�䣬˵��" + me->name(1) + "���²���ʵ����д��������ƭ�Ϸ�");
                command("say �����Ϸ�����Ҫ����һ�ʣ��������ˣ�");
                ANTI_ROBOT->get_question(me, this_object());
                return 1;
        }
        if(me->query_temp("xx_job")==1) {
                command("say ��С�ӣ���һ������û����ɾ͸������ҹ�����");
                return 1;
        }
        command ("say �����������������ҪһЩ�������㵽��ɽ��Щ�����Ұɡ���");
	waguan=new("/d/xingxiu/obj/waguan");
        me->set_temp("xx_job",1);
	if (!present("wa guan", me)) waguan->move(me);
	    message_vision("������˳�ִ���������ȡ��һ��С�߹��Ӹ��㡣\n", me);
		command ("say ����ȥ��أ�·��С�ġ���");
	return 1;

}


int ask_staff(){
	
	object me=this_player();
	object waguan;
	mapping fam;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("?");
		return 1;
	}
		
	if (me->query("tianshan")==1){
		command("say ��Ҫ���������ĵ���Ц��");
		return 1;
	}
	
	if (me->query_skill("pixie-jian",1)>=10){
		command("hmm");
		command("say ������ʧ�������������˹���");
		return 1;	
	}
			
	if (me->query_skill("staff", 1) < 250){
		command("say ������ȷ�����Ϊ������");
	}
	
	if (me->query_str() < 50) {
		command("say �������̫���ˣ��úö��������������Ұɡ�");
		return 1;
	}
	
	if (me->query_con() < 50) {
		command("say ����ڹ���Ϊ̫���ˣ��úö��������������Ұɡ�");
		return 1;
	}
		
	if (me->query_int() < 35) {
		command("sneer");
		command("say ������ѧ��������������̫���ȥ�úö�һ����ɡ�");
		return 1;
	}
		
	
        if(me->query_temp("canask")==1) {
                message_vision(HIG"$N΢΢һЦ����$n����һ�ԣ������ؽ���������������һ�С�\n", this_object(), this_player());
                message_vision(HIG"$n��$N�Ľ����£�����ɽ�ȷ�������һ���µ���⡣", this_object(), this_player());
                me->set("tianshan", 1);
                tell_object(this_object(),HIC"�����ɽ�ȷ������ˣ�");
        	me->add_skill("tianshan-zhang", 10);
                return 1;
        }
        
        
	return 1;

}
// �������ɣ�������أ��������Ž��ޱ�

int accept_object(object who, object ob){

	object me=this_player();
	mapping fam;
	int pot, exp;
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("?");
		return 0;
	}		

	if(ob->query("id")=="du dan"){

                if (this_player()->query_temp("xx_job")!=1 || ob->query("player")!=me->query("id")) {
			command("hehe");
			return 0;
		} else {
                        command("pat "+this_player()->query("id"));        
			command("say �����ģ�������Խ����Խ˳���ˡ�\n");
			// exp triple
			pot = random(80)+80;
			exp = 220 + random( 20 );
			me->add("combat_exp", exp);
			me->add("potential", pot);
			if(me->query("potential")>me->query("max_potential"))
				me->set("potential",me->query("max_potential"));
			log_file("/job/xx-zhua",sprintf("[%s] %s(%s) ץ��õ� %d �㾭��� %d ��Ǳ�ܡ�\n", ctime(time()), me->name(), me->query("id"), exp, pot));
			me->add("xingxiu/contribution", 1);
			me->delete_temp("xx_job");
			me->delete_temp("found");
			me->delete_temp("bug_hold");
			me->delete_temp("bug_out");
			call_out("destob",1,ob);
                        me->delete("passed_ding");
			return 1;
		}
	}
	if(ob->query("id")=="a zi"){

                {
                        command("say ̫���ˣ������а������ͽץ�����ˣ�\n");
                        command("say �����ģ��������ͽ�����ȹص��η�����ȥ��\n");
                        tell_object(me,"��������������޵��ӰѰ����ϳ�ȥ�ˡ�\n");
			pot = random(1000)+80;
			exp = 2200 + random( 20 );
			me->add("combat_exp", exp);
			me->add("potential", pot);
			if(me->query("potential")>me->query("max_potential"))
				me->set("potential",me->query("max_potential"));
			me->set("ask/ding", 1);
                     call_out("destob",1,ob);
			return 1;
		}
	}
	if(ob->query("id")=="noname book")
	{
		if(me->query("ask/ding")==1)
		{
			tell_object(me,"�⡭�������׽��ƪ������
ͽ������������һͳ�������������ˣ������Ȼ����ȡ�ã��պ��㵱ȻҲ��
����ϰ����Ϊʦ�����������¼����������ʦͽ��ͬ�о���\n");
			me->set("canbook",1);
			return 1;
		}
		else
		return notify_fail("������ŭ�������������Ǻε���ݣ����������������������Ҳ�Ҫ����\n");
	}
			
	if(ob->query("id")=="ling pai"){
		if(ob->query("player")!=me->query("id")){
			command("hehe");
			return 0;
		} else {
			command("hehehe");
			command("say �����ģ�����Щ�Գ��������ɵ�֪�����ɵ�������\n");
			if (ob->query("menpai")=="huashan" || ob->query("menpai")=="quanzhen")
				exp = 200 + random( 20 );
			else  if(ob->query("menpai")=="mingjiao") {
				command("say �š������̾�ȻҲ���Ҹ����ˡ�\n");
				//exp triple
				exp = 280 + random( 60 );
			} else	exp = 270+random(50);
			me->add("combat_exp", exp);
			log_file("/job/xx-zhua",sprintf("[%s] %s(%s) �����Ƶõ� %d �㾭�顣\n", ctime(time()),me->name(), me->query("id"), exp));			
			call_out("destob",1,ob);
                        me->delete("passed_ding");
			return 1;					
		}
	}
	
	
	command("hmm");
	command("say ���������ʲô��");
	return 0;
	
}	

void destob(object ob){
	destruct(ob);
}
