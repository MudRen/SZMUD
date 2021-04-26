//CODE OF SHENZHOU
//CODE BY NEWBE
//UPDATE BY SCATTER 2002/1/1 (UPDATE ���� code)

#include <ansi.h>
inherit NPC;

int do_da(string arg);
int ask_question();
int ask_jialu();
int do_learn(string arg);

void create()
{
        set_name("�׳�ʯ",({"bai changshi", "bai", "changshi"}));
        set("title",HIC"�����ܹ�"NOR);
        set("age",45);
        set("gender","����");
        set("long", "���Ǵ������Ķ����ܹܣ�ר�Ÿ����������ļ�鹤���� \n");
        set("inquiry", ([
                        "����" : (: ask_question :),
                        "����" : "��������,����Ҫ�Ȼش���һ�������⡻!",
                                                "jialu" : (: ask_jialu :),
                                                "����" : (: ask_jialu :),
        ]) );
        setup();
        carry_object("/clone/armor/cloth")->wear();
}

void init()
{
object me;
::init();
add_action("do_learn", "shixi");
add_action("do_learn", "ʵϰ");
if( interactive(me =this_player())&& !is_fighting()&& (int)me->query_temp("wenti"))
{
        add_action("do_da", "da");
        add_action("do_da", "answer");
}
}

int ask_jialu()
{
        object me = this_player();

        if ( me->query("newjob/jobtitle") == "����")
        {
                message_vision(NOR"�׳�ʯ��$N˵��: ���Ѿ�����������׳ʿ�γ����ԣ�\n"NOR, me);
                return 1;
        }

        if ( me->query("newjob/jobtitle") )
        {
                message_vision(NOR"�׳�ʯ��$N˵��: ���Ѿ���"+ me->query("newjob/jobtitle") +"����׳ʿ�γ����ԣ�\n"NOR, me);
                return 1;
        }

        if ( me->query("str") < 15 )
        {
                message_vision(NOR"�׳�ʯ��$N˵��: ���������ҲҪ����������\n"NOR, me);
                return 1;
        }

        if ( me->query("int") > 28 )
        {
                message_vision(NOR"�׳�ʯ��$N˵��: ������Լ��ߣ�׳ʿ���ܵ�������һ���˷�ѽ��\n"NOR, me);
                return 1;
        }

        if ( me->query("neili") < 300 )
        {
                message_vision(NOR"�׳�ʯ��$N˵��: ��������������׳ʿ���ǻ�ȥ�ڼ���ϰ�ɣ�\n"NOR, me);
                return 1;
        }

        message_vision(HIG"�׳�ʯ��$N˵��: �ðɣ��ӽ���������������ˣ��úõ�����ǰ;������\n"NOR, me);
        me->set("newjob/jobtitle", "����");
        
        return 1;
}


int ask_question()
{
     object me = this_player();
     if(me->query_temp("wenti"))
     {
        tell_object(me,"�㻹���Ȼش���һ��ɣ�\n");
        return 1;
     }
        
     if(me->query_temp("datiechang/enter"))
     {
        tell_object(me,"�׳�ʯ������ü˵���Ҳ���������ʹ������?\n");
        return 1;
     }
     
     if(me->query("combat_exp")<10000
       ||me->query("max_neili")<1000
       ||me->query("max_jingli")<1000
       ||me->query("str")<23
       ||me->query_skill("tiejiang", 1)<10)
     {
        tell_object(me,"�׳�ʯ��ϸ���˿���˵���㻹���Ȼ�ȥ����������!\n");
        return 1;
     }
                 
        message_vision(HIG"�׳�ʯ��$N˵������,����������һ�����ڿ�ʯ������,����˾��н����� (�� da��answer ���ش�)\n"NOR, me);
        
        switch( random(19) )
     {
             case 0:
                  message_vision(HIG"�׳�ʯ�ʵ���������������ʯ�����ڽ�����ʯ?\n"NOR, me);
                  message_vision(HIY"a:����ʯ  b:����ʯ  c:��ȸʯ  d:���ʯ\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 1:
                  message_vision(HIG"�׳�ʯ�ʵ���������������ʯ�����ڽ�����ʯ?\n"NOR, me);
                  message_vision(HIY"a:��ʯ  b:��ʯ  c:ˮ��ʯ  d:��ʯ\n"NOR, me);
                  me->set_temp("wenti", "d");
                  break;
             case 2:
                  message_vision(HIG"�׳�ʯ�ʵ���������������ʯ�ϲ����ڽ�����ʯ?\n"NOR, me);
                  message_vision(HIY"a:����ʯ  b:���ʯ  c:��ȸʯ  d:��ʯ\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 3:
                  message_vision(HIG"�׳�ʯ�ʵ��������������ֿ�ʯ����ͭ��ʯ?\n"NOR, me);
                  message_vision(HIY"a:Ҷ±��  b:����ʯ  c:��ȸʯ  d:��ʯ\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 4:
                  message_vision(HIG"�׳�ʯ�ʵ��������������ֿ�ʯ������ͭ��ʯ?\n"NOR, me);
                  message_vision(HIY"a:Ҷ±��  b:��ͭ��  c:��ȸʯ  d:��ͭ��\n"NOR, me);
                  me->set_temp("wenti", "a");
                  break;
             case 5:
                  message_vision(HIG"�׳�ʯ�ʵ��������������ֿ�ʯ����������ʯ?\n"NOR, me);
                  message_vision(HIY"a:������  b:��ʯ  c:������  d:��ʯ\n"NOR, me);
                  me->set_temp("wenti", "b");
                  break;
             case 6:
                  message_vision(HIG"�׳�ʯ�ʵ�����������������Ʒ��Ҫ�ý�����ʯ����֮��Ʒ�Ƴ�?\n"NOR, me);
                  message_vision(HIY"a:��  b:ˮ��  c:����  d:����\n"NOR, me);
                  me->set_temp("wenti", "d");
                  break;
             case 7:
                  message_vision(HIG"�׳�ʯ�ʵ�����������������Ʒ�ĵ�����ԭ���������ʯ�޹�?\n"NOR, me);
                  message_vision(HIY"a:����  b:�ž�  c:ʯī  d:����\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 8:
                  message_vision(HIG"�׳�ʯ�ʵ��������������ֽ�����ʯ���д��Ե���?\n"NOR, me);
                  message_vision(HIY"a:����  b:ͭ��  c:���  d:Ǧ��\n"NOR, me);
                  me->set_temp("wenti", "a");
                  break;
             case 9:
                  message_vision(HIG"�׳�ʯ�ʵ�����������������Ʒ�ĵ���ֱ���ɽ�����ʯ�Ƴɣ������뾭�������Ͷ���ļӹ�����?\n"NOR, me);
                  message_vision(HIY"a:����  b:ͭ��  c:˾��  d:��\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 10:
                  message_vision(HIG"�׳�ʯ�ʵ���������������ʯ��Ʒ�йص���?\n"NOR, me);
                  message_vision(HIY"a:�������  b:��������  c:��֦��Ҷ  d:��ͯ��Ů\n"NOR, me);
                  me->set_temp("wenti", "b");
                  break;
             case 11:
                  message_vision(HIG"�׳�ʯ�ʵ�����������������ʯ��Ʒ�йص���?\n"NOR, me);
                  message_vision(HIY"a:ˮ��  b:��¥  c:����  d:��˪̿\n"NOR, me);
                  me->set_temp("wenti", "b");
                  break;
             case 12:
                  message_vision(HIG"�׳�ʯ�ʵ�������������ͭ��ʯ������Ʒ�йص���?\n"NOR, me);
                  message_vision(HIY"a:��ͭ��ʱ��         b:ͭ������  c:ͭ������  d:ͭ����\n"NOR, me);  
                  me->set_temp("wenti", "a");
                  break;
             case 13:
                  message_vision(HIG"�׳�ʯ�ʵ�����������������ʯ��Ʒ�йص���?\n"NOR, me);
                  message_vision(HIY"a:��������  c:ͭ������  b:��֤��ɽ  d:�������\n"NOR, me);
                  me->set_temp("wenti", "d");
                  break;
             case 14:
                  message_vision(HIG"�׳�ʯ�ʵ�����������������ʯ������Ʒ�йص���?\n"NOR, me);
                  message_vision(HIY"a:��������  b:��������  c:�����޽�������˹��\n"NOR, me);
                  me->set_temp("wenti", "b");
                  break;
             case 15:
                  message_vision(HIG"�׳�ʯ�ʵ�������������Ǧ��ʯ������Ʒ�޹ص���?\n"NOR, me);
                  message_vision(HIY"a:Ǧ��  b:Ǧ��Ϊ  c:Ǧ����  d:Ǧӡ\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 16:
                  message_vision(HIG"�׳�ʯ�ʵ������ʽ�����ʯ����ͨʯͷ���濴��ȥ��ʲô�ֱ�?\n"NOR, me);
                  message_vision(HIY"a:һģһ����û������  b:����������һ�۾��ܱ�ʶ����  c:һ�㶼����Щ���𣬵�Ҫ�о�����˲��ܹ���ʶ����\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 17:
                  message_vision(HIG"�׳�ʯ�ʵ�������������������۵�̫�ߣ����ʺ������յķ�����������?\n"NOR, me);
                  message_vision(HIY"a:��  b:��  c:��ͭ  d:Ǧ\n"NOR, me);
                  me->set_temp("wenti", "a");
                  break;
             case 18:
                  message_vision(HIG"�׳�ʯ�ʵ���������������У��ĸ���һ�ֹ�������(����)�ı��?\n"NOR, me);
                  message_vision(HIY"a:˾��  b:����  c:Ǧ��  d:�콣ʦ\n"NOR, me);
                  me->set_temp("wenti", "c");
                  break;
             case 19:
                  message_vision(HIG"�׳�ʯ�ʵ������ʽ�Ĳ�״��ҪΪ?\n"NOR, me);
                  message_vision(HIY"a:��±���  b:�������ڵ���Ȼ��  c:Ҷ±��  d:���н�Ԫ�أ�����������ʯ\n"NOR, me);
                  me->set_temp("wenti", "b");
                  break;
        }
        
     add_action("do_da", "da");
     add_action("do_da", "answer");
     return 1;
}

int do_da(string arg)
{
        object me = this_player();
        if( !arg )
                return notify_fail("��Ҫ��ʲôѽ��\n");
        if( !me->query_temp("wenti") )
                return notify_fail("��Ҫ��ʲôѽ��\n");
        if( arg == me->query_temp("wenti"))
        {
        me->improve_skill("tiejiang", me->query_int()+random(50));
        command("say �ã���Ȼ���˲ţ�����Ŭ���ɡ�");
        message_vision(HIG"$N���������,�����Լ��Կ�ʯ���˽�������ߡ�\n"NOR, me);
        me->delete_temp("wenti", 1);
        me->set_temp("datiechang/enter", 1);
        return 1;
        }
        
        else if( arg != me->query_temp("wenti") )
        {
        message_vision(HIG"�׳�ʯ������$N��ͷ,��$N˵������˲�Ҫ��������Ŭ���ɡ�\n"NOR, me);
        me->delete_temp("wenti", 1);
        return 1;
        }
}






int accept_object(object who, object ob)
{
	if(who->query_temp("tiejiang/bailearn"))
	{
		tell_object(who, "�һ�û�����ء�\n");
		return 1;
	}
                
    if (ob->query("money_id") && ob->value() >= 100) 
	{
		message_vision("�׳�ʯͬ��ָ��$NһЩ����֪ʶ�����⡣\n", who);
        who->add_temp("tiejiang/bailearn", 2 + random(2));
        return 1;
    }
       
}





int do_learn(string arg)
{
	object me = this_player();


//	if(arg != "bai")
//	{
//		tell_object(me,"ʲô��\n");
//		return 0;
//	}

	if (me->query("jing") < 11)
	{
		tell_object(me, "�㾫�񲻼��С�");
		return 1;
	}

	if (!me->query_temp("tiejiang/bailearn"))
	{
		tell_object(me, "�㻹û��Ǯ���׳�ʯ��\n");
		return 1;
	}

	if (me->query_skill("tiejiang", 1) > 10)
	{
		tell_object(me, "��֪���ĺͰ׳�ʯ����ˡ�\n");
		return 1;
	}
		

	if (me->query_temp("tiejiang/bailearn"))
	{
		tell_object(me, "����׳�ʯ����йء�����֪ʶ�������ʡ�\n�����˰׳�ʯ��ָ�����ƺ���Щ�ĵá�\n");
		me->improve_skill("tiejiang", 5+random(5) ); 
		me->add_temp("tiejiang/bailearn", -1);
		me->add("potential", -1);
		me->add("jing", -10);


		if (me->query_temp("tiejiang/bailearn") < 1)
		{
			me->delete_temp("tiejiang/bailearn");
		}
		
		return 1;
	}

	return 1;

}
