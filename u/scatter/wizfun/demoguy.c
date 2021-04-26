// Code by Scatter
// demoguy.c
#include <ansi.h>
inherit NPC;

int ask_demo();
void do_menpai();
void do_job();
void do_cmds();
void do_weapon();
void do_chat();
void do_other();
void wudang_menu();
void wudang_bai();
void wudang_job_one();
void xx_menu();
void xingxiu_bai();
void xingxiu_job_one();

void create()
{
        set_name("���ְ�������", ({ "newbie wizard", "newbie", "wizard" }));
        set("gender", "����");
        set("age", 25);
        set("long", "�����������ɵ�����Э��Ա��\n");
 
		set("inquiry",
		([ 
			"demo" : (: ask_demo :),
		])); 


        set("combat_exp", 7000);
        set("shen_type", -1);
        set("attitude", "heroism");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}


int ask_demo()
{
	object me=this_player(), obnpc=this_object();
	command("say �ðɣ�����һ���ᾡ�����ܰ�����ģ�");
	write("-----------------------------------------------------------------------\n");
	write("|" + HIW + "                         �������ְ���һ����                        " + NOR + "  |\n");
	write("-----------------------------------------------------------------------\n");
	write("| 1) ������                                                           |\n");
	write("| 2) ������                                                           |\n");
	write("| 3) ָ����                                                           |\n");
	write("| 4) ������                                                           |\n");
	write("| 5) ������                                                           |\n");
	write("| 6) ������                                                           |\n");
	write("-----------------------------------------------------------------------\n");
	write("| ��ѡ�� select <����>  (����: select 1)                              |\n");
	write("-----------------------------------------------------------------------\n");
	write("\n");

	add_action("do_basemenu", "select");
	return 1;
}

int do_basemenu(string choi)
{
	object me=this_player(), obnpc=this_object();
	int arg;
	arg = atoi(choi);

	if(!arg)
	{
		write("��������Ҫ��ѡ�� (select <����>)\n");
		return 1;
	}

	remove_action("do_basemenu", "select");

	if( arg == 1 )
	{
		do_menpai();
	}

	else if(arg == 2)
	{
		do_job();
	}
	
	else if(arg == 3)
	{
		do_cmds();
	}
	
	else if(arg == 4)
	{
		do_weapon();
	}

	else if(arg == 5)
	{
		do_chat();
	}

	else if(arg == 6)
	{
		do_other();
	}
	else
	{
		write("��������Ҫ��ѡ�� (select <����>)\n");
		add_action("do_basemenu", "select");
		return 1;
	}
	return 1;
}


void do_menpai()
{
	object me=this_player(), obnpc=this_object();
	write("-----------------------------------------------------------------------\n");
	write("|" + HIW + "                         �������ְ���һ����                        " + NOR + "  |\n");
	write("-----------------------------------------------------------------------\n");
	write("| **************                                                      |\n");
	write("| *   ������   *                                                      |\n");
	write("| **************                                                      |\n");
	write("| 1)  ������ (��δ����)                                               |\n");
	write("| 2)  ؤ��   (��δ����)                                               |\n");
	write("| 3)  ������                                                          |\n");
	write("| 4)  ������ (��δ����)                                               |\n");
	write("| 5)  ������� (��δ����)                                             |\n");
	write("| 6)  ��Ĺ��   (��δ����)                                             |\n");
	write("| 7)  �䵱��                                                          |\n");
	write("| 8)  ����     (��δ����)                                             |\n");
	write("| 9)  ��ɽ��   (��δ����)                                             |\n");
	write("| 10) ����(ѩɽ��)  (��δ����)                                        |\n");
	write("| 11) ������   (��δ����)                                             |\n");
	write("| 12) �һ�     (��δ����)                                             |\n");
	write("| 13) ȫ���   (��δ����)                                             |\n");
	write("-----------------------------------------------------------------------\n");
	write("| ��ѡ�� select <����>  (����: select 1)                              |\n");
	write("-----------------------------------------------------------------------\n");
	write("\n");

	add_action("do_selectmenpai", "select");

	return;
}

int do_selectmenpai(string selnum)
{
	object me=this_player(), obnpc=this_object();
	int arg;
	arg = atoi(selnum);

	if(!arg)
	{
		write("��������Ҫ��ѡ�� (select <����>)\n");
		return 1;
	}

	remove_action("do_selectmenpai", "select");

	if( arg == 1 )
	{
		write("��δ����");
	}

	else if (arg == 2)
	{
		write("��δ����");
	}

	// 3 = ����
	else if (arg == 3)
	{
		xx_menu();
	}

	else if (arg == 4)
	{
		write("��δ����");
	}

	else if (arg == 5)
	{
		write("��δ����");
	}

	else if (arg == 6)
	{
		write("��δ����");
	}

	// 7 = �䵱
	else if (arg == 7)
	{
		wudang_menu();
	}

	else if (arg == 8)
	{
		write("��δ����");
	}

	else if (arg == 9)
	{
		write("��δ����");
	}

	else if (arg == 10)
	{
		write("��δ����");
	}
	
	else if (arg == 11)
	{
		write("��δ����");
	}

	else if (arg == 12)
	{
		write("��δ����");
	}
	
	else if (arg == 13)
	{
		write("��δ����");
	}

	else
	{
		write("��������Ҫ��ѡ�� (select <����>)\n");
		add_action("do_selectmenpai", "select");
		return 1;
	}
	return 1;
}


//********************************************
//XX MENU (START)
//********************************************
void xx_menu()
{
	object me=this_player(), obnpc=this_object();
	write("-----------------------------------------------------------------------\n");
	write("|" + HIW + "                         �������ְ���һ����                        " + NOR + "  |\n");
	write("-----------------------------------------------------------------------\n");
	write("| **************                                                      |\n");
	write("| *   ������   *                                                      |\n");
	write("| **************                                                      |\n");
	write("| 1) ��ΰ�������                                                     |\n");
	write("| 2) ���޹���ϵͳ (�۳�)                                              |\n");
	write("-----------------------------------------------------------------------\n");
	write("| ��ѡ�� select <����>  (����: select 1)                              |\n");
	write("-----------------------------------------------------------------------\n");
	write("\n");

	add_action("xingxiu_selmenu", "select");

	return;

}



int xingxiu_selmenu(string selnum)
{
	object me=this_player(), obnpc=this_object();
	int arg;
	arg = atoi(selnum);

	if(!arg)
	{
		write("��������Ҫ��ѡ�� (select <����>)\n");
		return 1;
	}

	remove_action("xingxiu_selmenu", "select");

	if( arg == 1 )
	{
		xingxiu_bai();
	}

    else if (arg == 2)
	{
		xingxiu_job_one();
	}

	else
	{
		write("��������Ҫ��ѡ�� (select <����>)\n");
		add_action("xingxiu_selmenu", "select");
		return 1;
	}
	return 1;
}

//*************************
//��ΰ������� START
//*************************

void xingxiu_bai()
{
	object me=this_player(), obnpc=this_object();
	command("say �����ھʹ���ȥ������ΰ������ް�");
	me->start_busy(30000);
	remove_call_out("xingxiu_bai_s1");
	call_out("xingxiu_bai_s1", 4, me, obnpc); 
	return;
}

void xingxiu_bai_s1(object me, object obnpc)
{
	me->move("/d/xingxiu/tianroad3");
	obnpc->move("/d/xingxiu/tianroad3");
	command("say ��ʵ���������Ǻܼ򵥵�");
	command("poke azi");
	command("say ֻҪ�� bai azi �Ϳ��������ұ���һ�θ��㿴");
	remove_call_out("xingxiu_bai_s2");
	call_out("xingxiu_bai_s2", 10, me, obnpc); 
	return;
}

void xingxiu_bai_s2(object me, object obnpc)
{
	write(HIY"***** ���� <bai azi> *****\n"NOR);
	write("����Ҫ�ݰ���Ϊʦ��\n"+ CYN +"����˵�����ðɣ��Ҿ��������ˡ�\n"+ NOR +"���Ͼ�������Ϊ���ӡ�\n\n������������Ϲ��������ؿ����ĸ���ͷ���е�����ʦ������\n��ϲ����Ϊ�����ɵĵ��������ӡ�\n");
	command("say ������ͳ�Ϊ����������������");
	remove_call_out("xingxiu_bai_s3");
	call_out("xingxiu_bai_s3", 17, me, obnpc); 
	return;
}

void xingxiu_bai_s3(object me, object obnpc)
{
	command("say ��������û�о���ֵ������, ����������Ǹǰ����, �����޿ɲ�������Ϊͽ�");
	command("xixi");
	remove_call_out("do_end");
	call_out("do_end", 5, me, obnpc); 
	return;
}
//*************************
//��ΰ������� END
//*************************





//*************************
//���޹���ϵͳ START
//*************************
void xingxiu_job_one()
{
	object me=this_player(), obnpc=this_object();
	command("say �����ھʹ���ȥ�������޵Ĺ���ϵͳ��");
	me->start_busy(30000);
	remove_call_out("xingxiu_job1_s1");
	call_out("xingxiu_job1_s1", 4, me, obnpc); 
	return;
}

void xingxiu_job1_s1(object me, object obnpc)
{
	me->move("/d/xingxiu/riyuedong");
	obnpc->move("/d/xingxiu/riyuedong");
	command("say ����������޿۳湤���ĵ�һ�ֳ�");
	command("say ����뿪ʼ�������� ask ding about job");
	command("say ���ұ���һ�θ��㿴��");
	remove_call_out("xingxiu_job1_s2");
	call_out("xingxiu_job1_s2", 7, me, obnpc); 
	return;
}

void xingxiu_job1_s2(object me, object obnpc)
{
	write(HIY"***** ���� <ask ding about job> *****\n"NOR);
	write("���򶡴�������йء�job������Ϣ��\n"+ CYN +"������˵���������������������ҪһЩ�������㵽��ɽ��Щ�����Ұɡ���\n"+ NOR +"������˳�ִ���������ȡ��һ��С�߹��Ӹ��㡣\n"+ CYN +"������˵��������ȥ��أ�·��С�ġ���\n"NOR);
	command("say ���ʱ�����Ͼͻ��һ����������  �߹�(Wa guan)");
	remove_call_out("xingxiu_job1_s3");
	call_out("xingxiu_job1_s3", 10, me, obnpc);
	return;
}

void xingxiu_job1_s3(object me, object obnpc)
{
	command("say �õ��߹��Ϳ��Կ�ʼѰ�ҳ���, ������ s, nw, ne, n ���Ե����޺���Ĵ���");
	remove_call_out("xingxiu_job1_s4");
	call_out("xingxiu_job1_s4", 5, me, obnpc);
	return;
}

void xingxiu_job1_s4(object me, object obnpc)
{
	me->move("/d/xingxiu/forest1");
	obnpc->move("/d/xingxiu/forest1");
	command("say ��������Դ� search here ��ʼ��Ѱ");
	command("say �ұ���һ�θ��㿴");
	remove_call_out("xingxiu_job1_s5");
	call_out("xingxiu_job1_s5", 4, me, obnpc);
	return;
}
	
void xingxiu_job1_s5(object me, object obnpc)
{
	write(HIY"***** ���� <search bug> *****\n"NOR);
	write("���������������ֽ���֦��Ҷ��������ϸѰ�Ҷ�����ټ���\n");
	command("say ���û�г�����ͼ����� search bug");
	remove_call_out("xingxiu_job1_s6");
	call_out("xingxiu_job1_s6", 6, me, obnpc);
	return;
}

void xingxiu_job1_s6(object me, object obnpc)
{
	write(HIY"***** ���� <search bug> *****\n"NOR);
	write("���������������ֽ���֦��Ҷ��������ϸѰ�Ҷ�����ټ���\n"+ HIG +"ͻȻ��һֻС�������˳�����Ѹ�ٵ������š�\n"NOR);
	write(HIR"�쾦��"+NOR+"(Zhu wa)\n");
	write(HIY"***** ���� <kou wa> *****\n"NOR);
	command("say �����������");
	remove_call_out("do_end");
	call_out("do_end", 10, me, obnpc);
	return;
}
//*************************
//���޹���ϵͳ END
//*************************





//********************************************
//WD MENU (START)
//********************************************
void wudang_menu()
{

	object me=this_player(), obnpc=this_object();
	write("-----------------------------------------------------------------------\n");
	write("|" + HIW + "                         �������ְ���һ����                        " + NOR + "  |\n");
	write("-----------------------------------------------------------------------\n");
	write("| **************                                                      |\n");
	write("| *   �䵱��   *                                                      |\n");
	write("| **************                                                      |\n");
	write("| 1) ��ΰ����䵱                                                     |\n");
	write("| 2) �䵱����ϵͳ (����)                                              |\n");
//	write("| 3) �䵱����ϵͳ (���)   (��δ����)                                 |\n");
//	write("| 4) �䵱������� (NPC)    (��δ����)                                 |\n");
	write("-----------------------------------------------------------------------\n");
	write("| ��ѡ�� select <����>  (����: select 1)                              |\n");
	write("-----------------------------------------------------------------------\n");
	write("\n");

	add_action("wudang_selmenu", "select");

	return;

}

int wudang_selmenu(string selnum)
{
	object me=this_player(), obnpc=this_object();
	int arg;
	arg = atoi(selnum);

	if(!arg)
	{
		write("��������Ҫ��ѡ�� (select <����>)\n");
		return 1;
	}

	remove_action("wudang_selmenu", "select");

	if( arg == 1 )
	{
		wudang_bai();
	}

	else if (arg == 2)
	{
		wudang_job_one();
	}
/*
	else if (arg == 3)
	{
		//wudang_job_two();
	}

	else if (arg == 4)
	{
		//wudang_npc();
	}
*/
	else
	{
		write("��������Ҫ��ѡ�� (select <����>)\n");
		add_action("wudang_selmenu", "select");
		return 1;
	}
	return 1;
}




//*************************
//��ΰ����䵱 START
//*************************
void wudang_bai()
{
	object me=this_player(), obnpc=this_object();
	command("say �����ھʹ���ȥ������ΰ����䵱��");
	me->start_busy(30000);
	remove_call_out("wudang_bai_s1");
	call_out("wudang_bai_s1", 4, me, obnpc); 
	return;
}

void wudang_bai_s1(object me, object obnpc)
{
	me->move("/d/wudang/shanmen");
	obnpc->move("/d/wudang/shanmen");
	command("say ��������䵱������");
	command("poke zhike");
	command("say ���������һ��Ҫ�ݵ���");
	command("say Ҫ�������Դ��� bai zhike");
	command("say �����ڱ���һ�θ��㿴");
	remove_call_out("wudang_bai_s2");
	call_out("wudang_bai_s2", 10, me, obnpc); 
	return;
}

void wudang_bai_s2(object me, object obnpc)
{
	write(HIY"***** ���� <bai zhike> *****\n"NOR);
	write("����Ҫ���������Ϊʦ��\n");
	write(CYN"�������˵�������䵱֮���������������˲�˥��ȫ���������Ծ�Ч����\n"NOR);
	write(CYN"�������˵��������ϰ����ǰ����ү���Ƿ�Ը��Ϊ�䵱������Щ���飿\n"NOR);
	write(HIY"������Ӧ�Ļ������룢Ը�⣢���֡�\n"NOR);
	write(HIY"***** ���� <Ը��> *****\n"NOR);
	command("say ���ʱ����ῴ�����µ�ѶϢ");
	remove_call_out("wudang_bai_s3");
	call_out("wudang_bai_s3", 20, me, obnpc); 
	return;
}

void wudang_bai_s3(object me, object obnpc)
{
	write("�����˵����Ը�⣡\n");
	write(CYN"�������������������Ц������\n�������˵�����ܺã��ܺã��ӽ�����������䵱һ����ϰѧͽ��\n�������˵����ϣ����ү���ڼ�Ŭ�����������������С�\n"NOR);
	command("say ��ʱ�����ǰ���䵱������, �ȵ��������Ź�����κ�����ٴ�һ�� bai zhike");
	command("say �ȵ��ڶ��� bai zhike �ɹ����������ʽ�䵱�Ĵ�������");
	remove_call_out("do_end");
	call_out("do_end", 25, me, obnpc); 
	return;
}
//*************************
//��ΰ����䵱 END
//*************************



//*************************
//�䵱����ϵͳ (����) START
//*************************
void wudang_job_one()
{
	object me=this_player(), obnpc=this_object();
	command("say �����ھʹ���ȥ����������䵱�����Ź�����");
	me->start_busy(30000);
	remove_call_out("wudang_job1_s1");
	call_out("wudang_job1_s1", 4, me, obnpc); 
	return;
}

void wudang_job1_s1(object me, object obnpc)
{
	me->move("/d/wudang/shanmen");
	obnpc->move("/d/wudang/shanmen");
	command("say ��������䵱������");
	command("say ����Ҳ�����䵱���Ź����ĵط�");
	command("say Ҫ��ʼ���ſ��Դ��� volunteer");
	command("say �����ڱ���һ�θ��㿴");
	remove_call_out("wudang_job1_s2");
	call_out("wudang_job1_s2", 10, me, obnpc); 
	return;
}

void wudang_job1_s2(object me, object obnpc)
{
	write(HIY"***** ���� <volunteer> *****\n"NOR);
	write("������ԸΪ֪�͵�������ɽ�š�\n" + CYN + "֪�͵������˶���˵�����������ã�������ȱ���֡�\n�������˵�������������úÿ��Űɣ��ɱ�����Щаħ������˻��ȥ��\n"NOR);
	command("say ���ʱ����Ϳ�ʼ������, ÿ������Լ 5 ��������");
	write("\n\n~~~~~~~~~ ����Ӻ� ~~~~~~~~~~~\n\n");
	remove_call_out("wudang_job1_s3");
	call_out("wudang_job1_s3", 20, me, obnpc);
	return;
}

void wudang_job1_s3(object me, object obnpc)
{
	command("say ����������ʱ�ῴ������ѶϢ");
	write("֪�͵�������˵��������ʱ�䵽����������ˣ�\n"+ CYN +"�������˵�����������ԸΪ�䵱Ч�����պ�س��䵱������\n����������������������ִ�Ĵָ�������ġ�\n"NOR);
	command("say ��������ɹ�������һ���䵱���Ź�����");
	remove_call_out("do_end");
	call_out("do_end", 22, me, obnpc);
}
//*************************
//�䵱����ϵͳ (����) END
//*************************


void do_job()
{
	object me=this_player(), obnpc=this_object();
	write("Jobs\n");
	return;
}


void do_cmds()
{
	object me=this_player(), obnpc=this_object();
	write("Commands\n");
	return;
}

void do_weapon()
{
	object me=this_player(), obnpc=this_object();
	write("Weapon\n");
	return;
}


void do_chat()
{
	object me=this_player(), obnpc=this_object();
	write("Chat\n");
	return;
}

void do_other()
{
	object me=this_player(), obnpc=this_object();
	write("Other\n");
	return;
}





//****************
//* END CLEAN UP *
//****************

void do_end(object me, object obnpc)
{
	me->move("/d/city/wumiao");
	obnpc->move("/d/city/wumiao");
	command("say лл��ʹ�����ְ��� NPC (V. 1.0 BETA)");
	me->start_busy(-30000);
	return;
}