// Code of ShenZhou
// /kungfu/class/emei/zhou.h
// yasuko: 2000/08/17
// mantian: may/21/2001
// kick out ppl for those learn pxj after bai zhou
// xiaojian for fixing all of the bugs June 22,2001
// xQin 06/01 add a log for expelled students 
#include <ansi.h>

void init()
{
	object ob,me;
	string *skname;	
        int i;
	ob=this_player();
	me=this_object();

	::init();

	set_heart_beat(1);

	if(interactive(ob)
		&& ob->query("family/family_name") =="������" 
		&& ob->query("gender") == "����" 
		&& (int)ob->query_skill("pixie-jian", 1) >=1) {
		if (!ob->query("pxj_warning")) {
			ob->set("pxj_warning",1);
			command("hmm");
			command("say ��а������,��Ϊ��ȥ͵ѧ��а����? �Ͽ�Ĺ�����,�����´μ����㶨������!\n");
		} else {
		command("look "+getuid(ob));
		command("hmm "+getuid(ob));
		command("sneer "+getuid(ob));
		command("say "+RANK_D->query_rude(ob)+"��Ȼѧ�˾����澭�ϵĹ���Ϊ��ȥѧ��а���������ҽ̵Ĳ����ã�");
		message_vision("\n$N����$n˵�����ӽ���������ʦͽ������������߰ɣ�\n\n", me, ob);
		tell_object(me, "\n�㱻ʦ�������ʦ���ˣ�\n\n");
		ob->delete("family");
		ob->set("title","��ͨ����");
		ob->set("score", 0);
		skills = ob->query_skills();
	
		if( mapp(skills) ) {
			skname = keys(skills);
			for(i=0; i<sizeof(skname); i++)
		        	if(SKILL_D(skname[i])->type()=="knowledge")
					skills[skname[i]] /= 2;
		        	else
					skills[skname[i]] = skills[skname[i]] * 2 / 3;
		}
		command("say ���ɣ�");
		ob->delete("pxj_warning");
		write_file("/kungfu/class/emei/zhou_log.c",
		sprintf("%s(%s) was expelled by zhou due to pxj %d(%d).\n", this_player()->query("id"), ctime(time()) ) ); 
		}
	}
}
string ask_jiuyin()
{
        object ob,me=this_player();
        if (me->query("family/master_name")!="������")
                return RANK_D->query_respect(this_player())+"�����ز���ʶ���γ������أ�";
        ob=new(__DIR__"obj/jiuyin-paper");
        if (present("juan pian",me)) return "�ף������ϲ��Ǵ��ž����澭������ô�������ң�";
        if (!ob) return "�ţ�����㵹��û���⣬ֻ�Ǹձ���ĵ��ӽ����ˣ����һ���������ʰɡ�";
        if (!me->query("jiuyin/first")) {
                command ("say ���ǵ�һ����������澭�ɣ�\n
            ������Ƭ���ܳ����ľ����澭��ԭ���������콣���ʵҲ����ʲô���˵Ķ�����
            ����ȥ�����ɡ�\n
            Ϊʦ��ǰ���᲻���£�ֻ֪���������ϵ���ʽ����(xiulian)����Ȼ��չ�ܿ죬��
            ��Խ����������Խ�����ա��������Ǳ������(lingwu)�����澭�е����У��վ���
            ��������ɡ���Ȼ������Ļ������ܶࡣ��Ҫ����ʲô�����׵ģ���ֱ�ӹ�������
            ѧ�ɡ�\n");
                me->set("jiuyin/first",1);
        }
        ob->move(me);
        message_vision("$n�ݸ�$Nһ����Ƭ��\n",me,this_object());
        command ("rumor "+me->query("name")+"Ū���˾����澭�ܳ�����");
        return "��סʦ���Ļ���ǧ��Ҫ̰������������ʱ��ͺ��Ī���ˡ�";
}

void attempt_apprentice(object ob)
{
    mapping fam;
    int last_betray,shen;
	
	//xiaojian: added a check before recruiting, i.e. won't recruit pxj dizi.

		if ((int)ob->query_skill("pixie-jian", 1) >=1) {
                        command("ah " + ob->query("id"));
                        command("say СŮ���볯͢������������֪��λ���˵����кι��ɣ�");
                        return;
                 }

        // Yinli and Qianzhu-wandu: by yasuko
        if ((int)ob->query_skill("qianzhu-wandu", 1) >=1 ) {
                command("sneer " + ob->query("id"));
                command("say ��λ" + RANK_D->query_respect(this_player())
                + "�������ԨԴ��ǳ�����¿ɲ��������ӵܡ�");
                return;
        }
        // Emei dizi(Linji-zhuang & Pixie-jian)��by yasuko
        if ( ob->query("family/family_name") == "������") {
                if ((int)ob->query_skill("linji-zhuang", 1) < 90) {
                        command ("say " + RANK_D->query_respect(this_player()) +
                                 "���ټ�ׯ��Ƿ�� ����ѧϰ�ϳ��书��\n");
                        return;
                }
                if ((int)ob->query_skill("pixie-jian", 1) >=1) {
                        command("sigh4 " );
                        command("say ��λ" + RANK_D->query_respect(this_player())
                                + "��Ȼ��ϡ�����ŵ��书���ֺα��������أ�");
                        return;
                }
        }
        // Betryer
        else {
                // Ppl who has betraied zhou and left from emei
        	last_betray=ob->query("zhou-betray");
        	if (last_betray>0 && last_betray != ob->query("betrayer") 
                && ob->query("combat_exp") >= 10000 ) {
		        command ("say " + RANK_D->query_respect(this_player()) +
			"��Ȼ�ѳ�����, �˿����ȴ������. \n");
        		command ("say " + RANK_D->query_respect(this_player()) + "��"
			+ob->query("family/family_name")+"���֣����ɿɲ���������");
        		return;
	        }
                // Gaibang Hinghand
        	if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 ) {
	        	command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
		        return;
	        }
                // Pixie-jian: by yasuko
                if ((int)ob->query_skill("pixie-jian", 1) >=1) {
                        command("ah " + ob->query("id"));
                        command("say СŮ���볯͢������������֪��λ���˵����кι��ɣ�");
                        return;
                 }
                // Peaceful life 1: by yasuko
                shen = ob->query("shen");
                if (shen >0) {
                        if (random(shen) >= 1000 ) {
                                command("xixi" + ob->query("id"));
                                command("say " + RANK_D->query_respect(this_player()) + 
                                "����Զ������ʦͽ֮��ʵ������ɱСŮ���ˡ�");
                                return;
                        }
                }
                if (shen <0) {
                        shen = 0 - shen;
                        if (random(shen) >= 1000 ) {
                                command("hmm" );
                                command("say ����" + RANK_D->query_respect(this_player()) + 
                                "�Ǻڵ����쵱�����������������ϴ�ĸ��棬���Ҿ������㡣");
                                return;
                        }
                }
                // Peaceful life 2: by yasuko
               if ( ((int)ob->query("PKS") || ob->query("death_times"))
                   && random((int)ob->query("PKS")/ob->query("death_times")) >10 ) {
                        command("lazy");
                        command("say ��λ" + RANK_D->query_respect(this_player()) + 
                        "��ô������ɱ����СŮ���µúܣ�����������ɡ�");
                        return;
                }
        }
	// Giving everybody one chance to enter emei
	if ((int)ob->query_skill("claw", 1) < 40) {
		command("say �ҿ�������ѧ�����澭�ϵĹ���ɣ���ȥѧ�������צ�������ɡ�");
		return;
	}
	if ((int)ob->query_skill("jiuyin-zhao", 1) < 40) {
		command("say �ҿ�������ѧ�����澭�ϵĹ���ɣ���ȥѧ��������ľ���צ�����ɡ�");
		return;
	}
	command("say �ðɣ���͸������ѧ�ɡ�"); 
	command("say ������ɼ�ס��, Ҫ��������ʦ��, �ҿɲ���������.\n");
	command("recruit " + ob->query("id"));
	ob->set("emei", 1);
	ob->set("zhou-betray", ob->query("betrayer"));
        command("whisper " + ob->query("id") + 
			" �´�������ʱ�������϶��ڽ�һ���������º������Ҿͻ����˴������.\n");
}
string ask_whip()
{
           object me = this_player();
           if (me->query("family/master_name")!="������")
           return RANK_D->query_respect(this_player())+"�����ز���ʶ���γ������أ�";
            if (me->query("feiyubian"))
            return "������˵���㲻���Ѿ�ѧ����ô?\n";
           if ( !me->query_temp("feiyu") )
          {
          me->set_temp("feiyu",1);
           return "��ͽ�����ҿ�û�о����澭�����ȰѾ����澭�ڹ��ؼ��������ң��ҽ���������\n";
         }
}
int accept_object(object who, object ob){ 
          object me=this_player();
           if (me->query_temp("feiyu") == 1)
           {
          if (ob->query("id")=="zhenjing" || ob->query("id")=="jiuying zhenjing")
          {
             command("jump");
               me->set_temp("feiyu",2);
               say ("�ɵĺã����ٰ��ҰѾ�����ץ�Ĳ���Ū���� !\n");
               call_out("destob",1,ob);
               return 1;
          }
         }
         else if (me->query_temp("feiyu") == 2)
         {
                if (ob->query("id")=="skin" || ob->query("id")=="yangpi" )
                {
                       command("grin");
                       say("Ϊʦ̫�����ˣ���ʲôҪ����˵�ɣ�\n");
               me->set_temp("feiyu",3);
            call_out("destob",1,ob);
               return 1;
                     }
             }
            command("angry");
            say ("�����ڻ�����Ҫ���� ��\n");
            return 1;
}
void destob(object ob)
{
          destruct(ob);
}
int ask_whip2()
{
         object me = this_player();
         object ob = this_object();
         if (me->query_temp("feiyu") != 3)
         {
         say("������˵����ƾʲô���㣡\n");
         return 1;
         }
         command("consider");
         say("������˵������........����Ҫ�ȿ��鿼������书��\n");
/*
         command("fight"+ me->query("id"));
         call_out("chk_feiyu",1,ob,me);
*/
         return 1;
}
int accept_fight()
{
       object me = this_object();
       object ob = this_player();
       if (ob->query_temp("feiyu")!=3)
       return 0;
       else {
       remove_call_out("checking");
       call_out("chk_feiyu", 1, me, ob);
       return 1; }
}
int chk_feiyu(object ob,object me)
{
         if (ob->is_fighting())
         {
                call_out("chk_feiyu",1,ob,me);
                return 1;
         }
         if ( !present(me, environment()) ) return 1;
         if ( ob->query("qi")*100/ob->query("max_qi") <50 && living(ob)) 
         {
                 say("������˵:����Ȼ�󸽶�ָ���������ƮƼ�޵��ؾ�!\n");
                 me->set("feiyubian",1);
                 me->set_skill("feiyu-bian",10);
                 me->delete_temp("feiyu");
                 return 1;
         }
}
