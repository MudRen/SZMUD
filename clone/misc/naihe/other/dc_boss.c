// �ĳ���boss  :)  ��/npc/dc_boss.c
// by naihe  2002-04-30
// ����޸ģ�2002-05-12 naihe
// ������ı��ļ�Դ�룬лл��
// ûǮʱ�ƶ���λ���������ǣ�131��132��261��262��615��616

#include <ansi.h>
string ask_duju();
inherit NPC;

int t_beta,t_playa,t_wina,t_betb,t_playb,t_winb,t_betc,t_playc,t_winc;
string gtz="open";
string gdn="open";
string gyz="open";

void create()
{
	set_name("���ա���",({"eileen nei","eileen","duchang boss"}));
	set("long","��������Ҷĳ����ϰ壬���Ž��ɫ�ľ�ͷ��������������飬���Ӹ�٬��
�������ϻ����¶����ȹ������ɢ���ų�������ĵ���Ϣ���㿴�˲���
������̾��ԭ���������Ů��Ȼ����������ˡ�\n\n");
	set("gender","Ů��");
	set("title","�����ĳ�");
	set("age",25);
	set("attitude","friendly");
	set("combat_exp",520);
	set_skill("literate",201);
	set_skill("force",20);
	set_skill("music",401);
set("no_refresh",1);
	set("inquiry",([
	    "name":"My name is Eileen nei. Hi~~",
	    "here":"�Ǻǣ�������ǹ����������ûǮ�ɲ�Ҫ����Ӵ��",
	    "rumors":"�����ĳ�������Ƚ�æ����ûʲô���ᵽ��ȥ���ߣ�����û����ʲô���ʵ��¡�",
	    "�ĳ�":"����������ʱ�����˵��������ߵĺö����飬���ú�����˼��
              ��һֱ������Ҫ���������",
	    "�ɷ�":"�һ�û�н�飬�������İ�������Ӵ��",
	    "husband":"I'm not marry,but I have my sweet heart now.",
	    "����":"��Ӯֻ��С�£��ܹ��ύ���Ѳ�������Ҫ�İ���",
    "�ľ�": (: ask_duju :),
	    "��ţ":"�ţ�ǽ�����ŶľֵĹ�أ��㿴���˾Ϳ�ʼ�ɣ�",
	    "����":"�ţ�ǽ�����ŶľֵĹ�أ��㿴���˾Ϳ�ʼ�ɣ�",
	    "һ�Ŷ���Ӯ":"�ţ�ǽ�����ŶľֵĹ�أ��㿴���˾Ϳ�ʼ�ɣ�",
	    ]));

	setup();
        carry_object(__DIR__"obj/dress")->wear();
}

  string ask_duju()
  {
          object me = this_player();

          if(wizardp(me))
          {
                  write("wiz������mewiz <��Ϸ> <״̬>�����Ż�ر�ĳ����Ϸ��\n");
                  write("wiz������xxxxx ��ѯ��ǰ��Ϸ����״̬��\n");
          }

          return "�ǣ���Ҫ����һ�������ӡ���ţ��һ�Ŷ���Ӯ����������ɣ�\n";
  }
void init()
{
        ::init();
        if (wizardp(this_player()))  add_action("do_xxxxx", "xxxxx"); // wiz ���Բ�ѯ��ֵ��
	if (wizardp(this_player()))  add_action("do_mewiz", "mewiz"); 
// wiz �����趨���Ż�ر�ĳ����Ϸ��
        add_action("do_touzi", "touzi");
	add_action("do_douniu", "douniu");
	add_action("do_yizhang","yizhang");
}   // �����ǵ�50�С�

int do_mewiz(string arg)
{
	string gname,gnow;
	if (!arg || sscanf(arg, "%s %s", gname, gnow) !=2)
	return notify_fail("��ʽ��mewiz <touzi/douniu/yizhang> <open/close>\n");

	if(gnow!="open" && gnow!="close")
	return notify_fail("��ʽ��mewiz <touzi/douniu/yizhang> <open/close>\n");

	if(gname == "touzi")
	{
		gtz=gnow;
		write("game 'touzi' is " + gnow + " .\n");
		return 1;
	}

	if(gname == "douniu")
	{
		gdn=gnow;
		write("game 'douniu' is " + gnow + " .\n");
		return 1;
	}

	if(gname == "yizhang")
	{
		gyz=gnow;
		write("game 'yizhang' is " + gnow + " .\n");
		return 1;
	}
	write("��ʽ��mewiz <touzi/douniu/yizhang> <open/close>\n");
	return 1;
}

int do_xxxxx()
{
	int tempsa,tempsb,tempsc;
	tempsa = (t_beta-t_wina);
	tempsb = (t_betb-t_winb);
	tempsc = (t_betc-t_winc);
     	write(""HIG"������Ϸ������"+t_playa+ "��  ����"+tempsa+" �� ��\n�����룺"+t_beta+" ��  ��֧����"+t_wina+" ��"NOR"\n");
     	write(""HIY"��ţ��Ϸ������"+t_playb+ "��  ����"+tempsb+" �� ��\n�����룺"+t_betb+" ��  ��֧����"+t_winb+" ��"NOR"\n");
     	write(""HIC"һ�Ŷ���Ӯ��Ϸ������"+t_playc+ "��  ����"+tempsc+" �� ��\n�����룺"+t_betc+" ��  ��֧����"+t_winc+" ��"NOR"\n");
	return 1;
}

int do_touzi(string arg)
{
	object me,qian,jj;
	int jjout,betmoney,mea,meb,mec,oba,obb,obc,meall,oball,mepower,obpower;
	string betname;
	me=this_player();
	qian=present("gold_money", me);
	jj=new("/clone/money/gold");

	if(gtz !="open")
		return notify_fail("�š��������Ҳ������Щ�����Ƕĵ��İɡ�\n");

	if (time()-query_temp("playtime")<3)
	{
	tell_object(me,"��һ�ֶľֲŸ��꣬�ȵ�һ��ɡ�\n");
	return 1;
	}

	if(!qian)
	{
		command("say ����Ц�ɣ�ûǮҲ���������ң�������");
                message_vision(""HIY"ֻ�������������˽�������$N������˳�ȥ��"NOR"\n",me);
		me->set("jingli",1);
		me->set("neili",1);
		me->set("qi",1);
		me->set("jing",1);
		me->set("food",20);
//                me->set("water",20);
//                me->move("/d/city/dc_dating");
              me->move("/clone/misc/naihe/dc_dating");
            message_vision(""HIY"$N�ӹ����������˳�����"NOR"\n",me);
		return 1;
	}

	if (!arg || sscanf(arg, "%d %s", betmoney,betname) !=2) 
	return notify_fail("�뿴���ľֵĹ���ٿ�ʼ�ɣ�\n");

	if(betname != "gold") return notify_fail("�뿴���ľֵĹ���ٿ�ʼ�ɣ�\n");

	if(betmoney<1) return notify_fail("��ô�������˼�������Ӯ�͸�Ǯ���㣿\n");
	if(betmoney>10) return notify_fail("�������ע�ƺ����˵㣬�Ҿ������䲻���ġ�\n");

	if((int)qian->query_amount() < betmoney*5)
	return notify_fail("�����Ǯ����̫���ɡ���������ҲҪ��ʵ���\n");

	t_playa++;
	message_vision(""HIY"$N�ó�"+betmoney+"���ƽ�������һ�ţ�˵�������Һ�����һ�ֱ����ӣ���"NOR"\n",me);

	mea=(1+random(6));
	meb=(1+random(6));
	mec=(1+random(6));
	meall=(mea+meb+mec);
	write("�мҿ��ĵ���Ϊ��"+mea+" "+meb+" "+mec+" ����"+meall+"�㣡\n",me);
	mepower=1;

	switch(random(2))
	{
		case 0 :
		oba=(1+random(6));
		obb=(1+random(6));
		obc=(1+random(6));
		break;

		case 1 :
		oba=(2+random(5));
		obb=(3+random(4));
		obc=(4+random(3));
		break;
	}

	oball=(oba+obb+obc);
	write("ׯ�ҿ��ĵ���Ϊ��"+oba+" "+obb+" "+obc+" ����"+oball+"�㣡\n",me);
	obpower=1;

	if(mea==meb && mea==mec)
	{
		mepower=5;
		write("�м�Ϊͬ��������Ϊ5����\n",me);
	}

	if(oba==obb && oba==obc)
	{
		obpower=5;
		write("ׯ��Ϊͬ��������Ϊ5����\n",me);
	}

	if(obpower!=5 && mepower==5)
	{
		jjout = (betmoney*mepower);
		jj->set_amount(jjout);
		t_wina+=jjout; // д���¼��
		jj->move(me);
		message_vision("���յ�����˵������������ͬ��ʤ����һ��$NӮ��"+jjout+"���ƽ����������������\n",me);
		set_temp("playtime",time());
		return 1;
	}

	if(obpower==5 && mepower!=5)
	{
		qian->add_amount(-betmoney*obpower);
		t_beta+=(betmoney*obpower); // д����Ϸ��ʷ��¼��
		command("giggle");
		message_vision("����΢Ц��˵������������ͬ��ʤ��$N����"+(betmoney*obpower)+"���ƽ���ô��������һ�ְɣ�\n",me);
		set_temp("playtime",time());
		return 1;
	}

	if(meall>oball)
	{
		jjout = (betmoney*mepower);
		jj->set_amount(jjout);
		t_wina+=jjout; // д����ʷ��¼��
		jj->move(me);
		message_vision("���յ�����˵������һ��$NӮ��"+jjout+"���ƽ����������������\n",me);
		set_temp("playtime",time());
		return 1;
	}

	qian->add_amount(-betmoney*obpower);
	t_beta+=(betmoney*obpower); // д����Ϸ��ʷ��¼��
	command("giggle");
	message_vision("����΢Ц��˵����$N����"+(betmoney*obpower)+"���ƽ���ô��������һ�ְɣ�\n",me);
	set_temp("playtime",time());
	return 1;
}

int do_douniu(string arg)
{
	object me,qian,jj;
	int jjout,betmoney,mepower,obpower;
	int aa,ab,ac,ad,ae,aall;
	int ba,bb,bc,bd,be,ball;
	string betname,mepk,obpk,winner;

	mepower=0;
	obpower=0;
	me=this_player();
	qian=present("gold_money", me);
	jj=new("/clone/money/gold");

	if(gdn !="open")
		return notify_fail("�š��������Ҳ������Щ�����Ƕĵ��İɡ�\n");

	if (time()-query_temp("playtime")<3)
	{
	tell_object(me,"��һ�ֶľֲŸ��꣬�ȵ�һ��ɡ�\n");
	return 1;
	}

	if(!qian)
	{
		command("say ����Ц�ɣ�ûǮҲ���������ң�������");
                message_vision(""HIY"ֻ�������������˽�������$N������˳�ȥ��"NOR"\n",me);
		me->set("jingli",1);
		me->set("neili",1);
		me->set("qi",1);
		me->set("jing",1);
		me->set("food",20);
		me->set("water",20);
//                me->move("/d/city/dc_dating");
              me->move("/clone/misc/naihe/dc_dating");
            message_vision(""HIY"$N�ӹ����������˳�����"NOR"\n",me);
		return 1;
	}

	if (!arg || sscanf(arg, "%d %s",betmoney,betname) !=2) 
	return notify_fail("�뿴���ľֵĹ���ٿ�ʼ�ɣ�\n");

	if(betname != "gold") return notify_fail("�뿴���ľֵĹ���ٿ�ʼ�ɣ�\n");

	if(betmoney<1) return notify_fail("��ô�������˼�������Ӯ�͸�Ǯ���㣿\n");
	if(betmoney>10) return notify_fail("�������ע�ƺ����˵㣬�Ҿ������䲻���ġ�\n");

	if((int)qian->query_amount() < betmoney*5)
	return notify_fail("�����Ǯ����̫���ɡ���������ҲҪ��ʵ���\n");

// ��ʽ��ʼ��Ϸ�ˡ�
	t_playb++;
	message_vision(""HIY"$N�ó�"+betmoney+"���ƽ�������һ�ţ�����˵�������Һ�����һ�ֶ�ţ����"NOR"\n",me);

	aa=(1+random(13));
	ab=(1+random(13));
	ac=(1+random(13));
	ad=(1+random(13));
	ae=(1+random(13));

	ba=(1+random(13));
	bb=(1+random(13));
	bc=(1+random(13));
	bd=(1+random(13));
	be=(1+random(13));


	if(aa>10) aa=10;
	if(ab>10) ab=10;
	if(ac>10) ac=10;
	if(ad>10) ad=10;
	if(ae>10) ae=10;

	if(ba>10) ba=10;
	if(bb>10) bb=10;
	if(bc>10) bc=10;
	if(bd>10) bd=10;
	if(be>10) be=10;

	write("�мҿ��������ǣ�"+aa+" "+ab+" "+ac+" "+ad+" "+ae+" "+"��\n",me);
	write("ׯ�ҿ��������ǣ�"+ba+" "+bb+" "+bc+" "+bd+" "+be+" "+"��\n",me);

	if(aa==10 && ab==10 && ac==10 && ad==10 && ae==10) mepower=5;

// �����Գ���������ָ���ж���������ֵ����ܳ�Ϊ10�ı�����Ȼ��ȷ������������ʣ���������ӡ�

	if(mepower==0)
	{
		if(aa+ab+ac == 10 || aa+ab+ac == 20 || aa+ab+ac == 30)
		{
			mepk="de";
			mepower=1;
		}
	}

	if(mepower==0)	
	{
		if(aa+ab+ad == 10 || aa+ab+ad == 20 || aa+ab+ad == 30)
		{
			mepk="ce";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(aa+ab+ae == 10 || aa+ab+ae == 20 || aa+ab+ae == 30)
		{
			mepk="cd";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(aa+ac+ad == 10 || aa+ac+ad == 20 || aa+ac+ad == 30)
		{
			mepk="be";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(aa+ac+ae == 10 || aa+ac+ae == 20 || aa+ac+ae == 30)
		{
			mepk="bd";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(aa+ad+ae == 10 || aa+ad+ae == 20 || aa+ad+ae == 30)
		{
			mepk="bc";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(ab+ac+ad == 10 || ab+ac+ad == 20 || ab+ac+ad == 30)
		{
			mepk="ae";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(ab+ac+ae == 10 || ab+ac+ae == 20 || ab+ac+ae == 30)
		{
			mepk="ad";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(ab+ad+ae == 10 || ab+ad+ae == 20 || ab+ad+ae == 30)
		{
			mepk="ac";
			mepower=1;
		}
	}

	if(mepower==0)
	{
		if(ac+ad+ae == 10 || ac+ad+ae == 20 || ac+ad+ae == 30)
		{
			mepk="ab";
			mepower=1;
		}
	}

	if(mepower==0) mepk="other";

// �����жϸü���������ֵ��
	if(mepk=="ab") aall=(aa+ab);
	if(mepk=="ac") aall=(aa+ac);
	if(mepk=="ad") aall=(aa+ad);
	if(mepk=="ae") aall=(aa+ae);
	if(mepk=="bc") aall=(ab+ac);
	if(mepk=="bd") aall=(ab+ad);
	if(mepk=="be") aall=(ab+ae);
	if(mepk=="cd") aall=(ac+ad);
	if(mepk=="ce") aall=(ac+ae);
	if(mepk=="de") aall=(ad+ae);

	if(aall>10) aall-=10;
	if(aall==10) mepower=3;
	if(aall==9 || aall==8) mepower=2;

	if(mepower==0) message_vision("�мҵ���ûţ��\n",me);

	if(mepower>0 && mepower<5) message_vision("�мҵ�����ţ"+aall+" ������Ϊ"+mepower+"����\n",me);

	if(mepower==5) message_vision("�м�����ţ����������Ϊ"+mepower+"����\n",me);

// �����������мҵ��жϣ�������ׯ�ҵ��жϣ�����������

	if(ba==10 && bb==10 && bc==10 && bd==10 && be==10) obpower=5;

// �����Գ���������ָ���ж���������ֵ���Ϊ10�ı�����Ȼ��ȷ������������ʣ���������ӡ�

	if(obpower==0)
	{
		if(ba+bb+bc == 10 || ba+bb+bc == 20 || ba+bb+bc == 30)
		{
			obpk="de";
			obpower=1;
		}
	}

	if(obpower==0)	
	{
		if(ba+bb+bd == 10 || ba+bb+bd == 20 || ba+bb+bd == 30)
		{
			obpk="ce";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(ba+bb+be == 10 || ba+bb+be == 20 || ba+bb+be == 30)
		{
			obpk="cd";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(ba+bc+bd == 10 || ba+bc+bd == 20 || ba+bc+bd == 30)
		{
			obpk="be";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(ba+bc+be == 10 || ba+bc+be == 20 || ba+bc+be == 30)
		{
			obpk="bd";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(ba+bd+be == 10 || ba+bd+be == 20 || ba+bd+be == 30)
		{
			obpk="bc";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(bb+bc+bd == 10 || bb+bc+bd == 20 || bb+bc+bd == 30)
		{
			obpk="ae";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(bb+bc+be == 10 || bb+bc+be == 20 || bb+bc+be == 30)
		{
			obpk="ad";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(bb+bd+be == 10 || bb+bd+be == 20 || bb+bd+be == 30)
		{
			obpk="ac";
			obpower=1;
		}
	}

	if(obpower==0)
	{
		if(bc+bd+be == 10 || bc+bd+be == 20 || bc+bd+be == 30)
		{
			obpk="ab";
			obpower=1;
		}
	}

	if(obpower==0) obpk="other";

// �����жϸü���������ֵ��
	if(obpk=="ab") ball=(ba+bb);
	if(obpk=="ac") ball=(ba+bc);
	if(obpk=="ad") ball=(ba+bd);
	if(obpk=="ae") ball=(ba+be);
	if(obpk=="bc") ball=(bb+bc);
	if(obpk=="bd") ball=(bb+bd);
	if(obpk=="be") ball=(bb+be);
	if(obpk=="cd") ball=(bc+bd);
	if(obpk=="ce") ball=(bc+be);
	if(obpk=="de") ball=(bd+be);

	if(ball>10) ball-=10;
	if(ball==10) obpower=3;
	if(ball==9 || ball==8) obpower=2;

	if(obpower==0) message_vision("ׯ�ҵ���ûţ��\n",me);

	if(obpower>0 && obpower<5) message_vision("ׯ�ҵ�����ţ"+ball+" ������Ϊ"+obpower+"����\n",me);

	if(obpower==5) message_vision("ׯ������ţ����������Ϊ"+obpower+"����\n",me);

//  ��ʼ�ж�ʤ����	

	if(mepower>obpower) winner="player";
		else winner="npc";

	if(mepower!=1 && mepower!=0 && mepower!=2 && mepower==obpower) command("say ��ҵ�һ����ׯ��Ӯ��");

	if(mepower==1 && mepower==obpower)
	{
		if(aall>ball) winner="player";
			else winner="npc";
		if(aall==ball) command("say ��ҵ�һ����ׯ��Ӯ��");
	}
	
	if(winner=="player")
	{
		jjout = (betmoney*mepower);
		jj->set_amount(jjout);
		t_winb+=jjout;
		jj->move(me);
		message_vision("���յ�����˵������һ��$NӮ��"+jjout+"���ƽ����������������\n",me);
		set_temp("playtime",time());
		return 1;
	}

	if(obpower==0 && mepower==0)
	{
		command("say ��Ҷ�û��ţ��ׯ��Ӯ��");
		obpower=1;
	}

	qian->add_amount(-betmoney*obpower);
	t_betb+=(betmoney*obpower); // д����Ϸ��ʷ��¼��
	command("giggle");
	message_vision("����΢Ц��˵����$N����"+(betmoney*obpower)+"���ƽ���ô��������һ�ְɣ�\n",me);
	set_temp("playtime",time());
	return 1;
}


int do_yizhang(string arg)
{
	object me,qian,jj;
	int jjout,betmoney,mea,oba,meb,obb;
	string betname,winner,mehs,obhs;
	me=this_player();
	qian=present("gold_money", me);
	jj=new("/clone/money/gold");

	if(gyz !="open")
		return notify_fail("�š��������Ҳ������Щ�����Ƕĵ��İɡ�\n");

	if (time()-query_temp("playtime")<3)
	{
	tell_object(me,"��һ�ֶľֲŸ��꣬�ȵ�һ��ɡ�\n");
	return 1;
	}

	if(!qian)
	{
		command("say ����Ц�ɣ�ûǮҲ���������ң�������");
                message_vision(""HIY"ֻ�������������˽�������$N������˳�ȥ��"NOR"\n",me);
		me->set("jingli",1);
		me->set("neili",1);
		me->set("qi",1);
		me->set("jing",1);
		me->set("food",20);
		me->set("water",20);
//                me->move("/d/city/dc_dating");
              me->move("/clone/misc/naihe/dc_dating");
            message_vision(""HIY"$N�ӹ����������˳�����"NOR"\n",me);
		return 1;
	}

	if (!arg || sscanf(arg, "%d %s", betmoney,betname) !=2) 
	return notify_fail("�뿴���ľֵĹ���ٿ�ʼ�ɣ�\n");

	if(betname != "gold") return notify_fail("�뿴���ľֵĹ���ٿ�ʼ�ɣ�\n");

	if(betmoney<1) return notify_fail("��ô�������˼�������Ӯ�͸�Ǯ���㣿\n");
	if(betmoney>10) return notify_fail("�������ע�ƺ����˵㣬�Ҿ������䲻���ġ�\n");

	if((int)qian->query_amount() < betmoney)
	return notify_fail("�����Ǯ����̫���ɡ���������ҲҪ��ʵ���\n");

	t_playc++;
	message_vision(""HIY"$N�ó�"+betmoney+"���ƽ�������һ�ţ�˵�������Һ�����һ��һ�Ŷ���Ӯ����"NOR"\n",me);

	mea=(1+random(13));
	switch(random(4))
	{
		case 0 :
		mehs="��";
		meb=0;
		break;

		case 1 :
		mehs="��";
		meb=1;
		break;

		case 2 :
		mehs="��";
		meb=2;
		break;

		case 3 :
		mehs="��";
		meb=3;
		break;
	}
	write("�мҿ������ǣ�"+mehs+mea+" ��\n",me);

	switch(random(2))
	{
		case 0 :
		oba=(1+random(13));
		break;

		case 1 :
		oba=(6+random(8));
		break;
	}

	switch(random(4))
	{
		case 0 :
		obhs="��";
		obb=0;
		break;

		case 1 :
		obhs="��";
		obb=1;
		break;

		case 2 :
		obhs="��";
		obb=2;
		break;

		case 3 :
		obhs="��";
		obb=3;
		break;
	}
	write("ׯ�ҿ������ǣ�"+obhs+oba+" ��\n",me);

	if(mea==1) mea=100;
	if(oba==1) oba=100;
	if(mea>oba) winner="player";
	if(mea<oba) winner="npc";
	if(mea==oba)
	{
		if(mehs>obhs) winner="player";
		if(mehs<obhs) winner="npc";
		if(mehs==obhs) winner="none";
	}

	if(winner=="none" || winner=="player")
	{
		if(winner=="none") message_vision("���վ��ȵض�$N˵��������ҵ��ƾ�Ȼ��ͬ��������һ��������ô����������\n                    ��ֲ��㣬���⳥һЩ�ƽ����ɡ�\n",me);
		jjout = betmoney;
		jj->set_amount(jjout);
		t_winc+=jjout;
		jj->move(me);
		message_vision("���յ�����˵������һ��$NӮ��"+jjout+"���ƽ����������������\n",me);
		set_temp("playtime",time());
		return 1;
	}

	qian->add_amount(-betmoney);
	t_betc+=(betmoney); // д����Ϸ��ʷ��¼��
	command("giggle");
	message_vision("����΢Ц��˵����$N����"+betmoney+"���ƽ���ô��������һ�ְɣ�\n",me);
	set_temp("playtime",time());
	return 1;
}
/* ��һ�㶼����LPC�Ϳ�ʼ�����ĳ��������ڣ�������һ�����ˡ����뻹����ͦ��
��˼�ľ��������ˣ��������Ʒ��CODE���¸�ʽ����д�Ҳ��ԡ���ʲô�ֶζ������ˣ���
����д�������NPC �������һ�����ˣ�һ����򵥵��Ķĳ���Ҳ���������ա���ʵ�ܶ�
�ط���CODEд�ö�ͦ�����������ġ���Ҳ���Ǻܷ����������������� 
�κ� --naihe 2002-05-06 ��ï�� */
