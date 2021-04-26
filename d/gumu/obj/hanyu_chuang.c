// Program make by fengyu, Describing by Jiuer.
// /d/gumu/obj/hanyu_chuang.c.
// 2002/8/12.

#include <ansi.h>
inherit ITEM;

//��������������--------------------------------------------------------------------------------

object me,ob;

//����������------------------------------------------------------------------------------------

int do_bedin();				// action ����ϴ���
int do_bedout();			// action ����´���

//������ʽ��ʼ��--------------------------------------------------------------------------------

void create()
{
	set_name(HIW"����"NOR, ({"hanyu chuang","chuang","bed"}));
	set_weight(200000);
	if( clonep() )
		set_default_object(__FILE__);
	else {

		set("long","    ���ǹ�Ĺ��ʦ���Ż���������Ѫ���������ຮ֮�أ��������ɼ��"+
			   "֮���ڳ���\n�ĺ����Ƴɵ�һ���Ϲź���"+HIW"(  bed )"NOR+"��ʵ"+
	  		   "��ϰ�ϳ��ڹ���������˯����������\n��"+HIW"(  gotobed )"NOR+
		   	   "��һ��ֵ���ƽ��������ʮ�ꡣ���������Ų�ϯ��һ���ײ�������\n"+
			   "�����������ܲ��˴˴��ĺ����������´�"+HIW"( getout )"NOR+
			   "��\n"
		   );
                set("unit", "��");
                set("material", "steal");
	     } 
	setup();
}


void init()
{
        add_action("do_bedin", "gotobed");
	add_action("do_bedout","getout");
}

int do_bedin() //�ϴ�---------------------------------------------------------------------------
{
//�ֲ�����������

	string wss; 		// ws ��Ӣ����˼�ǻ����������� ws �Ľ�����ʱʹ�á�
	int wsi; 		// int ���Ƶ� ws ��
	object *inv; 		// ���� ��ǰ���� inventory ��Ʒ��������ң������顣

	ob=this_player();

//����Ѿ�������ڴ��ϣ��˳���

	inv = all_inventory(environment(ob));
	for(wsi=0; wsi<sizeof(inv); wsi++)
		{if( (int)inv[wsi]->query_temp("hanyu_chuang") != 0)
			return notify_fail("�����Ѿ������ˣ�����ֻ��һ����ʹ�á�\n");
		}

//��ʾ����ϴ�������temp("hanyu_chuang")=1��
	me=ob;
	message_vision("$N�������Ϻ��񴲣�������ȥ��\n", me);
	me->delete_temp("apply/short");
	wss=me->short();
	me->set_temp("apply/short",wss+HIW"  �������ں����ϣ�"NOR); //��look���������ID��
	me->set_temp("hanyu_chuang",1);
	set_heart_beat(1); 					//��ʼ������
	return 1;
}

int do_bedout()//�´�----������ڴ��ϵ����ʹ��getout�����ʾ�´����Ҳ������㡣---------------
{
	ob=this_player();
	if((int)ob->query_temp("hanyu_chuang") != 0)
		{
		 ob->delete_temp("apply/short");
		 ob->delete_temp("hanyu_chuang");
		 message_vision("$N�����������������˺��񴲡�\n", ob);
		 set_heart_beat(0);				//�ر�������
		 return 1;
		}	
	return notify_fail("ʲô��\n");
}

void heart_beat()//������ϴ���ÿ�������Զ�ִ��һ�Ρ�-----------------------------------------
{
	int f=(int)me->query_skill("force");			//�ڹ��ȼ���
	int mnl=(int)me->query("max_neili");			//���������
	int q=(int)me->query("qi");				//��ǰ����
	int qc=f/10+1;						//ÿ����������������
	int nla,nl,gg;						//Ҫ�ӵ������͵�ǰ�������͸��ǡ�

	if( me->query_skill_mapped("force") != "yunu-xinjing")	//����ñ���ڹ����˳���
		{
		 tell_object(me, HIB"�����һ����Ϯ�������ɴ��˸�������\n"NOR);
		 if( (int)me->query("qi") < 20 )		//����Ѿ������ˣ��˳���
			{
			 message_vision("$N�Ӵ��Ϲ���������\n", me);
			 me->delete_temp("apply/short");
			 me->delete_temp("hanyu_chuang");
			 set_heart_beat(0);
			 return;
			}
		 me->add("qi",-20);
		 return;
		}

	if(mnl>999) return;					//��������������1000���˳���

	if (q<qc)						//��ֹ�ε���
		{if(q<1)
			qc=0;
		 else
		 	qc=q-1;
		}	

	if((int)me->query_temp("pending/exercise") != 0)	//������ڴ�����
		{
		 nla=(qc + qc) * (1000-mnl) / 1000;
		 me->add("neili",nla);	
		 if( random(10)==1 )
			tell_object(me, "��������ڵ��������ϵı��������������پ�ȫ���泩��\n");
		}
	else
		{
		 nla=qc + qc * (1000-mnl) / 1000;
		 me->add("neili",nla);	
		 me->add("qi",-qc);				//��û������������
		 if( random(10)==1 )
		 	tell_object(me, "����������������Զ��Ŀ�ʼ���ߣ��پ�һ�����ɡ�\n");
		}

	nl=(int)me->query("neili");				//��ǰ������
	gg=(int)me->query("con");				//����ֵ��

	if (nl+1 > mnl*2)
		{if (mnl > f*gg*2/3)
			{tell_object(me, "���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
                         me->set("neili", mnl);
                         return;
                	}
                 else 
			{me->add("max_neili", 2);
			 me->set("neili", mnl+2);
			 tell_object(me, "����������������㣡��\n");                        
			 return; 
			}
		}	

	return;
}
