//Cracked by Yujie
// /kungfu/class/jobnpc/cl_situ.c ˾ͽ��
// by 10 / 2001

#ifndef BANGS
#define BANGS  "/d/huanghe/"
#endif

#define BANGYIN     BANGS + "obj/bangyin"
#define BANGLING    BANGS + "obj/bangling"
#define POSFILE "/d/forest/sifang/clb_pos"
#define BANGSKILLS  BANGS + "skills"
#define OFFICE  "/d/forest/clxiaoting"
#define CLB_POS  "/topten/clb_file"
#define SF_DIR "/kungfu/class/changle/clsifang"


inherit NPC;
inherit F_CLEAN_UP;
inherit F_SAVE;

#include <ansi.h>
#include <localtime.h>

#include "/d/huanghe/changle/info_beauty.h"

int ask_join();
int be_got(string,string);
string ask_job();
string ask_kaichu();
string ask_skills();
string ask_position();
string ask_life();
string ask_recover();
string query_save_file()
{
        return "/data/npc/cl_situ";
}

string *positions = ({
        "������",
        "������",
        "������",
        "ʨ����",
        "������",
        "ӥѸ��",
        "������",
});

void create()
{
	set_name("˾ͽ��", ({ "situ heng", "situ" }));
	set("nickname", "��צ����");
        set("fam", "���ְ�");
	set("long",
"����һ����ĸߴ󣬵���Щ���ݵ������ˣ�˫�ۺܳ�����ץ����\n"
"��������Ҳ����һ����\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 50);
	set("int", 28);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 800);
	set("max_neili", 1000);
        set("neili", 1000);
	set("jiali", 60);
	set("combat_exp", 300000);
	set("score", 10000);

	set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("claw",  120);
        set_skill("strike", 80);
        set_skill("staff", 80);

        set_skill("poison", 80);

        set_skill("huagong-dafa", 120);
	set_skill("zhaixinggong", 120);
        set_skill("sanyin-zhua",  120);
        set_skill("chousui-zhang", 80);
        set_skill("tianshan-zhang", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
        map_skill("parry", "sanyin-zhua");
        map_skill("claw",  "sanyin-zhua");
        map_skill("strike", "chousui-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("claw",  "sanyin-zhua");
        

        set("inquiry", ([
                "���" : (: ask_join :),
                "����" : (: ask_kaichu :),
                "join" : (: ask_join :),
                "����" : (: ask_job :),
                "job" : (: ask_job :),
                "�书" : (: ask_skills :),
                "skills" : (: ask_skills :),
                "���ְ�" : "���ְ����𽭺���ָ�տɴ���������������",
                "������" : "�������Ϳ๦�ߣ�������������Ϊ�ܹܡ�",
                "�����" : "�������Ϳ๦�ߣ�������������Ϊ�ܹܡ�",
                "����ʯ" : "�������Ϳ๦�ߣ�������������Ϊ�ܹܡ�",
                "����" : (: ask_position :),
                "position" : (: ask_position :),
                "����" : (: ask_life :),
                "life" : (: ask_life :),
                "recover" : "���ڹ��͵����Զ��ۻ��ģ��Ѿ�����Ҫ�ָ��ˡ�",
                "�ָ�" : "���ڹ��͵����Զ��ۻ��ģ��Ѿ�����Ҫ�ָ��ˡ�",
        ]));
        
        
	setup();

        carry_object("/clone/misc/cloth")->wear();
 //     carry_object("/clone/weapon/feizhua")->wield();
}

     string ask_kaichu() 
{

             object me = this_player() , ob = this_object();
object ling;
object sf_d;
             string myfam,mypos,msg,*msg_a,nowmsg,sfn; 
             int lastscore,score,i; 
             myfam = (string)query("fam"); 
             if( (string)me->query_temp("bangs/fam") != myfam ) 
                     return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�"; 

             if( !(ling = present("bang ling", me)) ) 
                     return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��"; 

             if (!stringp(mypos = me->query("clbpos")))
                     return "�㲢�Ǳ���������"; 

       me->delete("clbpos"); 
            if( strlen ( msg = read_file(POSFILE)) > 0 )  
       { msg_a = explode(msg,"\n"); 
       msg=""; 
       nowmsg = me->query("id")+"("+ mypos + ")"; 
       for(i=0; i< sizeof(msg_a); i++) 
               if(msg_a[i] != nowmsg) msg += ( msg_a[i]+"\n"); 
write_file(POSFILE,msg,1); 
       }
       switch(mypos) 
       {
case "������" : write_file("/d/forest/sifang/sifang1_file","",1);sfn="1";break;
case "ʨ����" : write_file("/d/forest/sifang/sifang2_file","",1);sfn="2";break;
case "������" : write_file("/d/forest/sifang/sifang3_file","",1);sfn="3";break; 
case "ӥѸ��" : write_file("/d/forest/sifang/sifang4_file","",1);sfn="4";break; 
case "������" : write_file("/d/forest/sifang/sifang5_file","",1);sfn="5";break; 
       }
if ( sf_d = find_object(SF_DIR + sfn) ) 
        destruct(sf_d); 

message_vision(HIM"��Ϊ�������ͣ�$N��"+mypos+"����һְȡ����\n"NOR,me);
command("chat ��λ���������ǣ�"+ me->name()+ "�������ͳ��ְ�"+ mypos +"����һְ��\n"); 
return "";
}

string ask_job()
{
        object ob = this_player();

        if( (string)ob->query_temp("bangs/fam") != "���ְ�" )
                return RANK_D->query_rude(ob) + "Ī����������Ұ�����ܰɡ�";

        return "�йؾ�������������ȥ�ʱ�������";
}

string ask_position()
{
        object *obj, ling, wage, me = this_player(), ob = this_object();
        string *poss, *leftpos, pos, myfam,allpos,pplid,mypos,str;
        int i, score, bonus, period, record,j;

        if( is_fighting() )
                return RANK_D->query_rude(me) + "Ϲ����û������æ�ţ���";

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

        
        if( stringp(pos = me->query_temp("bangs/pos")) ) {
                period = uptime() - (int)me->query_temp("bangs/pos_time");
                if( period < 900 )
                        return "������ô�̵�ʱ���ڲ������ж����Ϊ���Ժ����ð���Ѳ��" + pos + "�ɡ�";

                score = (int)me->query("clbscore");
                bonus = score - (int)me->query_temp("bangs/pos_score");
                me->set_temp("bangs/pos_score", score);
                me->set_temp("bangs/pos_time", uptime());

                if( bonus < 1000 )
                        return pos + "������ֺܲ�ѽ������Щ�����ڸ���";

                command("nod");
//              bonus *= (score / 1000 + 1);
//              This line is the old code, if player stays on line and cumulates the
//              score, it can be very big, for example, online 15 hours can get about 20k score
//              20000 / 1000 + 1 = 21, if he only ask xiang zhu one
//              bonus = (20000 - 500) * 21 = 409500, and later bonus /= 3, add_exp = bonus +random(bonus)
//              So a player can get 200k exp like this.

//              So instead of multiply, add the bonus, so it won't increase by factors. 
                bonus = bonus/500;
                wage = new("/clone/money/gold");
                record = bonus + random(bonus/2);
                wage->set_amount(record);
                wage->move(me);
                message_vision("$Nת���ó�һ������ݸ�$n��\n", this_object(), me);
                log_file("test/BangPos", sprintf("%s��%sʱ���Ͻ%s%s����%s���ƽ�\n", me->query("name"), ctime(time()), myfam, pos, chinese_number(record)));

                bonus /= 3;
                me->add("combat_exp", bonus + random(bonus));
                return pos + "����Ĺ�Ͻ�£�������ֲ���";
        }
        
        if( (int)me->query("combat_exp") < 50000 )
                return RANK_D->query_rude(me) + "������δ��̫���˰ɡ�";

        if( (score = (int)me->query("clbscore")) < 200000 )
                return "��ƾ����㹦��Ҳ��������֮λ��";

        leftpos = positions;
        if(stringp(allpos=read_file(POSFILE)))
        {	
        	poss = explode(allpos,"\n");
        	for (i=0 ;i < sizeof(poss) ;i++)
        	{	sscanf(poss[i],"%s(%s)",pplid,pos);
	             	leftpos = filter_array(leftpos,"be_got",this_object(),pos);
        	}
        }
        
	if( !sizeof(leftpos) )
                return "�������е�����֮λ������ռ�š�";

        mypos = leftpos[random(sizeof(leftpos))];
        me->set_temp("bangs/pos", mypos);
        me->set("clbpos",mypos);
        me->set_temp("bangs/pos_time", uptime());
        me->set_temp("bangs/pos_score", score);
        str = me->query("id")+ "(" + mypos + ")\n";
        if(stringp(read_file(POSFILE)))
                str = read_file(POSFILE) + str;
        write_file(POSFILE,str,1);
        
                
        me->set_temp("apply/short",
   ({ HIR + myfam + mypos + "���� "NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));
        log_file("test/BangPos", sprintf("%s��%sʱ����%s%s����\n", me->query("name"), ctime(time()), myfam, pos));
        command("congra");
        command("chat ��λ���������ǣ�"+ me->name()+ "�ӽ��쿪ʼ���γ��ְ�"+ me->query("clbpos")+"������ϣ���ܰ��Ұ﷢����\n");

        return "�Ұ�" + mypos + "�и����㣬���Ҫ����������";

}

/*
string ask_recover()
{	
	object ling, sf_d, me=this_player(), ob=this_object();
	string myfam,mypos,msg,*msg_a,nowmsg,sfn;
	int lastscore,score,i;
			
	if( is_fighting() )
                return RANK_D->query_rude(me) + "Ϲ����û������æ�ţ���";

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

        if( !(ling = present("bang ling", me)) )
                return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

        if( (string)ling->query("owner") != me->query("id") )
                return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";
                
        if (me->query_temp("recovered"))
		return "��ղ��Ѿ��ָ����ˡ�";
	
	if (!intp( lastscore = me->query("clbscore")))
		return "����ǰ��Ϊ���Ұ������£��ָ�ʲôѽ��";
	
	ling->add("score",lastscore);
	score = ling->query("score");
	if ( stringp (mypos = me->query("clbpos")) )
	{	if ( score < 200000 )
		{	me->delete("clbpos");
			if( strlen ( msg = ob->query("clb_pos")) > 0 )
			{   
                	msg_a = explode(msg,"\n");
                	msg="";
                	nowmsg = me->query("id")+"("+ mypos + ")";
                        for(i=0; i< sizeof(msg_a); i++)
                        	if(msg_a[i] != nowmsg) msg += ( msg_a[i]+"\n");
                        ob->set("clb_pos",msg);
                        save();
                        }
                        switch(mypos)
                        {
                        case "������" : write_file("/d/forest/sifang/sifang1_file","",1);sfn="1";break;
                        case "ʨ����" : write_file("/d/forest/sifang/sifang2_file","",1);sfn="2";break;
        		case "������" : write_file("/d/forest/sifang/sifang3_file","",1);sfn="3";break;
        		case "ӥѸ��" : write_file("/d/forest/sifang/sifang4_file","",1);sfn="4";break;
        		case "������" : write_file("/d/forest/sifang/sifang5_file","",1);sfn="5";break;
        		}
        		if ( sf_d = find_object(SF_DIR + sfn) )
        			destruct(sf_d);
        		
                        message_vision(HIM"��Ϊ����̫�$N��"+mypos+"����һְ������\n"NOR,me);
		}
		else
		{	me->set_temp("bangs/pos", mypos);
        		me->set_temp("bangs/pos_time", uptime());
        		me->set_temp("bangs/pos_score", score);
                        
        		me->set_temp("apply/short",
   			({ HIR + myfam + mypos + "���� "NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));
   			message_vision("$N��"+mypos+"����һְ�ָ��ˡ�\n",me);
   		}
	}
	me->set_temp("recovered",1);
	return "���ϴ��ڱ���Ļ��¼�Ϸ����ָ��ˡ�";
}
*/

string ask_life()
{
        object me = this_player();
        string myfam, *beautys, beauty;

        if( is_fighting() )
                return RANK_D->query_rude(me) + "Ϲ����û������æ�ţ���";

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

        if ( me->query("combat_exp")< 5000 )
        {	command("shake "+me->query("id"));
        	return "����������ӿ����޷�ʤ�����£�����ȥ�ұ������ɡ�";
        }
        
        if( uptime() < (int)query("joytime") + 60 + random(20) ) {
        if (random(2))
        {        command("lazy");
                 return "�Ϸ�����Դ�û����Ȥ��";
        }
        command("shake");
        return "�Ϸ�����û�¸��ˣ���ȥ�ʱ�����Ҫ��ɰɡ�";
        }

        beautys = keys(info_beauty);
        beauty = beautys[random(sizeof(beautys))];

        command("hehe " + query("id"));
        me->set_temp("bangs/beauty", beauty);
        set("joytime", uptime());
        return "���" + beauty + "��������ô�������Ϸ��⼸�춼û˯�Ⱦ���";
}

int accept_object(object who, object ob)
{
        object ling, room;
        string myfam, beauty;
        int bonus, record,reduce;

        myfam = query("fam");
        if( who->query_temp("bangs/fam") != myfam ) 
                return notify_fail(name() + "��ŭ�����󵨣���ı������������\n");

        if( !(room = environment()) )
                return notify_fail(name() + "��ŭ�������һ��ܶ���˵�ɣ�\n");

        if( base_name(room) != OFFICE )
                return notify_fail(name() + "��ŭ�������һ��ܶ���˵�ɣ�\n");

        if( !stringp(beauty = who->query_temp("bangs/beauty")) )
                return notify_fail(name() + "��ŭ���������Ϸ��˽�²�������ģ�\n");

        if( !ob->is_character() )
                return notify_fail(name() + "��ŭ���������ö������Լ��ðɣ�\n");

        if( ob->query("gender") != "Ů��" )
                return notify_fail(name() + "��ŭ�����Ϸ������û��Ȥ��\n");

        if( ob->query("name") != beauty )
                return notify_fail(name() + "��ŭ�������Ϸ�Ļ����ǲ�ס��\n");
        
        if (userp(ob))
        	return notify_fail(name() + "��ŭ����������������ƭ�Ϸ��Ŷ�û�У�\n");

	if( userp(ob) )
		return notify_fail(name() + "��ŭ������������Ҹ��˻���������ƭ�Ϸ�\n");
            
        who->delete_temp("bangs/beauty");
        ob->move(this_object());
        call_out("destroy_beauty", 1, ob);
        bonus = info_beauty[beauty] * 80000 / (80000 + (int)who->query("combat_exp"));
                
        reduce = ((int)ob->query("eff_qi")*100)/(int)ob->query("max_qi");
        
        if ( reduce < 20 ) return notify_fail(name() + "��ŭ�������˵�ֻʣ�°������ˣ����Լ��������ðɣ�\n");
        
        if (reduce != 100)	bonus = bonus * reduce/150;
        if (bonus < 10)		bonus = 10;
        record = bonus*2 + random(bonus/2);
                
        who->add("combat_exp", record);
        who->add("shen", -(record/4));
        log_file("test/BangWomen",  sprintf("%s��%sʱ�Ϲ�%s��%s�����\n", who->query("name"), ctime(time()), beauty, chinese_number(record)));
	bonus = bonus + random(bonus/4);
       
       	who->add("clbscore",bonus);
       	write(HIW"����ι������õ�"+chinese_number(bonus)+"�㹦�͵㣬" + chinese_number(record)+ "�㾭��ֵ��\n"NOR);
       
        command("haha");
        command("say �ã��ã��ã�" + myfam + "�������¼�ǧ�����������ְ����Ļ��ģ�");
        return 1;
}       

void destroy_beauty(object ob)
{
        if( ob )  destruct(ob);
}

int be_got(string leftpos, string pos)
{
	if (leftpos == pos)	return 0;
	return 1;
}

#include "/d/huanghe/npc/bangzhu.h";
