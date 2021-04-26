
                        // Code of ShenZhou
// yu.c ������
// Update by Scatter
// V 1.0


#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_zwz();
string ask_drug1();
string ask_drug2();
string ask_drug3();
string ask_drug4();

void create()
{
        set_name("�����", ({ "yu daiyan", "yu" }));
        set("nickname", "�䵱����");
        set("long", "�����䵱�����е������������ƹܵ�ҩ����\n"
                    "ֻ������Ŀ�㲣�����֧���Ź����ƺ�ʮ�ֳ�����\n"
                    "��˵����ǰ�򱻴����Դ������ָ������֫����������Ժ�����������Ƶ����޷�Ȭ����\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 5);
        set("int", 38);
        set("con", 10);
        set("dex", 20);

        set("max_qi", 500);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 0);
        set("combat_exp", 1050000);
        set("shen", 80000);

        set_skill("force", 120);
        set_skill("taiji-shengong", 120);
        set_skill("dodge", 100);
        set_skill("tiyun-zong", 100);
        set_skill("strike", 90);
        set_skill("mian-zhang",90);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("taiji-jian", 100);
        set_skill("literate", 150);
        set_skill("taoism", 150);
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("strike", "mian-zhang");
        map_skill("sword", "taiji-jian");
        prepare_skill("strike", "mian-zhang");
        create_family("�䵱��", 2, "����");
        set("inquiry", ([
        "��ҩ��" : "���ﻹû����ȫ���ţ������ĵȴ���\n",
        "���Ľⶾ��" : (:ask_drug1:),
        "���Ʊ�����" : (:ask_drug2:),
        "�������ĵ�" : (:ask_drug3:),
        "�׻�������" : (:ask_drug4:),
                "�����߽���" : (: ask_zwz :),
        
        ]));
        
        set("drug1_count", 5);
        set("drug2_count", 5);
        set("drug3_count", 5);
        set("drug4_count", 3);
        
        setup();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

string ask_drug1()
{ 
        mapping fam; 
        object me, ob,*obs;
        me=this_player();
        ob=this_object();
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
        
        if (me->query_temp("obtained_drug1"))
        {
        command("hmm "+me->query("id"));
        return "���Ľⶾ�������Ѿ�����������";
        }
        
        obs = filter_array(children("/clone/drug/tianxin.c"), (: clonep :));
        if (sizeof(obs) > 5)
return "�������ˣ����Ľⶾ�����Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";

        if (query("drug1_count") < 1)
return "�������ˣ����Ľⶾ�����Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";
        
        ob=new("/clone/drug/tianxin");
        ob->move(me);
        add("drug1_count", -1);
        me->set_temp("obtained_drug1", 1);
        message_vision("�����ת�������ң��ڼ�����������һ��С��ƿ�������浹��һ��ҩ�������$N��\n",me);
        return "�ðɣ�������һ�����Ľⶾ�����м�Ҫ���á�";
}
        
string ask_drug2()
{ 
        mapping fam; 
        object me, ob,*obs;
        me=this_player();
        ob=this_object();
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
        
        if (me->query_temp("obtained_drug2"))
        {
        command("hmm "+me->query("id"));
        return "���Ʊ����費���Ѿ�����������";
        }
        
        obs = filter_array(children("/clone/drug/sanhuang-wan.c"), (: clonep :));
        if (sizeof(obs) > 5)
return "�������ˣ����Ʊ����趼�Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";

        if (query("drug2_count") < 1)
return "�������ˣ����Ʊ����趼�Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";
        
        ob=new("/clone/drug/sanhuang-wan");
        ob->move(me);
        add("drug2_count", -1);
        me->set_temp("obtained_drug2", 1);
        message_vision("�����ת�������ң��ڼ�����������һ��С��ƿ�������浹��һ��ҩ�������$N��\n",me);
        return "�ðɣ�������һ�����Ʊ����裬�м�Ҫ���á�";
}

string ask_drug3()
{ 
        mapping fam; 
        object me, ob,*obs;
        me=this_player();
        ob=this_object();
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
        
        if (me->query_temp("obtained_drug3"))
        {
        command("hmm "+me->query("id"));
        return "�������ĵ������Ѿ�����������";
        }
        
        obs = filter_array(children("/clone/drug/huxin"), (: clonep :));
        if (sizeof(obs) > 5)
return "�������ˣ��������ĵ����Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";

        if (query("drug3_count") < 1)
return "�������ˣ��������ĵ����Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";
        
        ob=new("/clone/drug/huxin");
        ob->move(me);
        add("drug3_count", -1);
        me->set_temp("obtained_drug3", 1);
        message_vision("�����ת�������ң��ڼ�����������һ��С��ƿ�������浹��һ��ҩ�������$N��\n",me);
        return "�ðɣ�������һ���������ĵ����м�Ҫ���á�";
}

string ask_drug4()
{ 
        mapping fam; 
        object me, ob,*obs;
        me=this_player();
        ob=this_object();
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
        return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
        
        if (me->query_temp("obtained_drug2"))
        {
        command("hmm "+me->query("id"));
        return "�׻������費���Ѿ�����������";
        }
        
        obs = filter_array(children("/clone/drug/baihu.c"), (: clonep :));
        if (sizeof(obs) > 5)
                return "�������ˣ��׻������趼�Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";

        if (query("drug2_count") < 1)
return "�������ˣ��׻������趼�Ѿ�������ͬ�������ˣ���Ҫ�������ơ�";
        
        if (me->query("combat_exp") < 50000 )
        {
        command("look "+me->query("id"));
return "�׻����������Ƽ�Ϊ���ף�����Ŀǰ�Ĺ���Ӧ�ò�����Ҫ�ģ��Ժ���˵�ɡ�";
        }
        ob=new("/clone/drug/baihu");
        ob->move(me);
        add("drug2_count", -1);
        me->set_temp("obtained_drug2", 1);
        message_vision("�����ת�������ң��ڼ�����������һ��С��ƿ�������浹��һ��ҩ�������$N��\n",me);
        return "�ðɣ�������һ�Ű׻������裬�����ò����м�Ҫ���á�";
}


int ask_zwz()
{
        object me = this_player();

                if ( !me->query("zhenwu/4x") )
                {
                        command("say ������Ķ����ᣬ�һ����ܽ��㡣");
                        return 1;
                }

                if ( me->query_temp("zhenwu/asking") )
                {
                                command("say ���ǲ���ѧ���ǲ��ǣ�");
                                return 1;
                }
                if ( me->query("zhenwu/3x") )
                {
                                command("say ���Ѿ���������Ҫѧ���顣");
                                return 1;
                }
        if ( me->query("combat_exp") < 100000 )
                {
                                command("say ���ʵս���黹���㣬������ò�Ҫѧ�������߽��󡹡�");
                return 1;
                }
        if ( me->query_skill("taiji-shengong", 1) < 100 )
                {
                                command("say ����ڹ�������������ѧ�������߽��󡹶���ٺ�����һ�棬�Ժ���˵�ɡ�");
                                return 1;
                }
        if ( me->query_skill("taoism", 1) < 100 )
                {
                                command("say ��Ե�ѧ�ķ��������˽⣬�����㲻����ᡸ�����߽��󡹵����⡣");
                                return 1;
                }
        if ( me->query("int") < 20 )
                {
                                command("say ������Բ����ߣ��������������߽��󡹵��������ڡ�");
                                return 1;
                }
        if ( me->query("max_neili") < 1000 )
                {
                                command("say ��������������ã���ȥ��û��������Ұɣ�");
                                return 1;
                }
        if ( me->query_skill("parry") < 100 )
                {
                                command("say �䵱�ľ�ѧ��������˸գ�����һ�㶫�����мܲ�ס����ôѧ�������߽��󡹣�");
                                return 1;
                }
                if ( me->query("jing") < 300 )
                {
                                command("say �����ڹ���ƣ�ͣ���ȥ��Ϣһ�°ɡ�");
                                return 1;
                }
        if ( me->query("jingli") < 2000 )
                {
                                command("say ��ϰ�������߽��󡹲���һ��������£��ҿ��������ڵ����������ʺ�����");
                                return 1;
                }
		if ( me->query("neili") < 2000)
		{
			command("say ��ϰ�������߽��󡹲���һ��������£������ڵ����������ʺ�����");
			return 1;
		}

                command("say �������ѧ��");
                write(HIY"��ѧ�Ļ���� xiang\n"NOR);
                me->set_temp("zhenwu/asking", 1);

                add_action("do_xiang", "xiang");
        
                return 1;

}

int do_xiang(string arg)
{
        object me = this_player();

                command("say �ðɣ��Ҿʹ����㡸�����߽��󡹵ĵ��ĸ�λ�ã��������Ƿ�������Ϳ�����ˡ�");
        command("say �����ร�");
                
                remove_action("do_xiang", "xiang");
                me->start_busy(20);

        call_out("stepone",5,me);
                return 1;
}

void stepone(object me)
{
                command("say ������ʵ�����������������");
        message_vision(HIW"������ڿ��л��˺ܶ�Ȧ����Ȧ��СȦ����Ȧ����Ȧ��˫Ȧ����Ȧ��Ȧ��Ȧ����Ȧ����Ȧ����Ȧ����Ȧ��\n"NOR, me);
        message_vision(HIY"������������У��������ջص���\n"NOR, me);
        command("say �㿴������");

		message_vision(NOR"$N������ĥ����������ڵ���Ҫ����\n"NOR, me);

        call_out("steptwo",10,me);
}

void steptwo(object me)
{
        int rndnum;
        rndnum = random(210);

                me->delete_temp("zhenwu/asking");

        if(rndnum < 190)
        {
                message_vision(HIR"$NͻȻһ����ѣ����ǰ��һ���ƺ����ڴ�ת����\n"NOR, me);
                me->unconcious();
                return;
        }
        else
        {
                message_vision(HIC"$N�����󷨣��鶯�糤�ߣ��������ڹ꣬���󷨴�������\n"NOR, me);
                me->set("zhenwu/3x", 1);
                return;
        }
}
