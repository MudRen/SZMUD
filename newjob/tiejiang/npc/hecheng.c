//CODE OF SHENZHOU
//CODE BY NEWBE

#include <ansi.h>
inherit NPC;

int do_dig();
int do_da(string arg);

void create()
{
	set_name("�γ�",({"he cheng", "he", "cheng"}));
        set("title",HIC"��ܹ�"NOR);
        set("age",35);
        set("gender","����");
        set("long", "���ǿ���ļ�ܹ���ʱ��ʱ�ʿ�һЩ����,�Է�����͵���� \n");

        setup();
        carry_object("/clone/armor/cloth")->wear();
}

void init()
{
object me;
::init();
if(interactive(me =this_player())&& !is_fighting()&& (int)me->query_condition("bonze_drug" ) < 10)
{
remove_call_out("greeting");
call_out("greeting",1,me);
this_player()->apply_condition("bonze_drug", 20);
}
}

void greeting(object me)
{
if(!me || environment(me) !=environment()) return;

	message_vision(HIG"�γɶ�$N˵��������������һ������,����˾��н����� (�� da��answer ���ش�)\n"NOR, me);

	switch( random(19) )
     {
             case 0:
                  message_vision(HIG"�γ��ʵ��������ڿ��Ƿ�Ҫ����?\n"NOR, me);
                  message_vision(HIY"1) Ҫ    2) ��Ҫ\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 1:
                  message_vision(HIG"�γ��ʵ��������ܷ������ڼ��ο�?\n"NOR, me);
                  message_vision(HIY"1) ��    2) ����\n"NOR, me);
                  me->set_temp("wenti", "2");
                  break;
             case 2:
                  message_vision(HIG"�γ��ʵ��������ڿ����Ҫ ����, ����, ��, �� ����?\n"NOR, me);
                  message_vision(HIY"1) ��    2) ����\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 3:
                  message_vision(HIG"�γ��ʵ��������ڿ������ر��·���? ���߻��?\n"NOR, me);
                  message_vision(HIY"1) ��    2) ����\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 4:
                  message_vision(HIG"�γ��ʵ�����������ڵ������ʲô?\n"NOR, me);
                  message_vision(HIY"1) ����    2) ʯ��   3) ��    4) ��ɳ\n"NOR, me);
                  me->set_temp("wenti", "3");
                  break;
             case 5:
                  message_vision(HIG"�γ��ʵ�������˭�ſ����ڿ�?\n"NOR, me);
                  message_vision(HIY"1) ����    2) Ů��    3) ���Ͻ���\n"NOR, me);
                  me->set_temp("wenti", "3");
                  break;
             case 6:
                  message_vision(HIG"�γ��ʵ��������ڿ���û������? ( ����Ҫ���پ��� )\n"NOR, me);
                  message_vision(HIY"1) ��    2) û��\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 7:
                  message_vision(HIG"�γ��ʵ��������������ڿ�?\n"NOR, me);
                  message_vision(HIY"1) ��    2) ����    3) ����   4) ɽ·\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 8:
                  message_vision(HIG"�γ��ʵ�������ʲôʱ��ſ���ȥ�ڿ�?\n"NOR, me);
                  message_vision(HIY"1) ����    2) ����    3) ����\n"NOR, me);
                  me->set_temp("wenti", "3");
                  break;
             case 9:
                  message_vision(HIG"�γ��ʵ�������Ҫ��ʲô���ڿ�?\n"NOR, me);
                  message_vision(HIY"1) ����    2) ľ֧    3) ��    4) ǹ   5) ���ϽԷ�\n"NOR, me);
                  me->set_temp("wenti", "5");
                  break;
             case 10:
                  message_vision(HIG"�γ��ʵ�������һ�˿����ڼ���ο�?\n"NOR, me);
                  message_vision(HIY"1) һ��    2) ʮ��    3) ���    4) ������\n"NOR, me);
                  me->set_temp("wenti", "4");
                  break;
             case 11:
                  message_vision(HIG"�γ��ʵ��������ڿ��ǲ���ÿ�ζ���ɹ�?\n"NOR, me);
                  message_vision(HIY"1) ��    2) ����\n"NOR, me);
                  me->set_temp("wenti", "2");
                  break;
             case 12:
                  message_vision(HIG"�γ��ʵ�����������ʲôָ�����ڿ�?\n"NOR, me);
		  message_vision(HIY"1) dig    2) wa 3) ����������\n"NOR, me);	
                  me->set_temp("wenti", "3");
                  break;
             case 13:
                  message_vision(HIG"�γ��ʵ��������ڿ���û���Ѷ�?\n"NOR, me);
                  message_vision(HIY"1) ��    2) û��\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 14:
                  message_vision(HIG"�γ��ʵ�������Ҫ��ʲô���˿�?\n"NOR, me);
                  message_vision(HIY"1) ��    2) ����    3) ����    4) �ɻ�\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 15:
                  message_vision(HIG"�γ��ʵ��������ڿ���������ʲô��?\n"NOR, me);
                  message_vision(HIY"1) ����    2) ����    3) ˮ��    4) ����\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 16:
                  message_vision(HIG"�γ��ʵ��������к�Ů�ڿ��зֱ���?\n"NOR, me);
                  message_vision(HIY"1) ��    2) û��\n"NOR, me);
                  me->set_temp("wenti", "2");
                  break;
             case 17:
                  message_vision(HIG"�γ��ʵ��������ڿ��� exp ��?\n"NOR, me);
                  message_vision(HIY"1) ��    2) ����\n"NOR, me);
                  me->set_temp("wenti", "1");
                  break;
             case 18:
                  message_vision(HIG"�γ��ʵ��������ڿ��� literate ��?\n"NOR, me);
                  message_vision(HIY"1) ��    2) ����\n"NOR, me);
                  me->set_temp("wenti", "2");
                  break;
             case 19:
                  message_vision(HIG"�γ��ʵ��������ڿ�Ҫ����?\n"NOR, me);
                  message_vision(HIY"1) Ҫ    2) ��Ҫ\n"NOR, me);
                  me->set_temp("wenti", "2");
                  break;
        }
        
     add_action("do_da", "da");
     add_action("do_da", "answer");
     add_action("do_dig", "dig");
     add_action("do_dig", "wa");
     return ;
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
        me->improve_skill("caikuang", me->query_int()+random(100));
	command("say �ã���Ȼ���˲ţ�����Ŭ���ɡ�");
        message_vision(HIG"$N���������,�����Լ��Ĳɿ���������ߡ�\n"NOR, me);
        me->delete_temp("wenti", 1);
        me->apply_condition("bonze_drug", 80);
        return 1;
        }
	
	else if( arg != me->query_temp("wenti") )
        {
        message_vision(HIG"�γ�������$N��ͷ,��$N˵������˲�Ҫ��������Ŭ���ɡ�\n"NOR, me);
        me->delete_temp("wenti", 1);
        me->apply_condition("bonze_drug", 70);
        return 1;
        }
}

int do_dig()
{
	object me = this_player();
	if(me->query_temp("wenti"))
	return notify_fail("�㻹���Ȼش��ҵ�����ɣ�");
}
