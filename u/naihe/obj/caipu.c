// ѧ���ˣ������ף�  caipu.c
// by naihe  02-06-28

inherit ITEM;
#include <ansi.h>

string zzz,xxx,
zzz="���ļ�Ŀ¼���ԣ��䲻������",
xxx="�������Ѿ���";


void create()
{
	set_name(HIW"�ش�����"NOR, ({"cai pu"}));
	set_weight(1000);
	set("long","һ�����صĲ��ף�������������ζ��ʽ���������ƺ�����һ��Ů��֮�֡�\n����Կ�һ�¾��嶼д��Щʲô��shows����\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 200);
	}
	setup();
}

void init()
{
	if(wizardp(this_player()))
	{
		add_action("do_cooks","cooks");
		add_action("do_gocook","gocook");
	}
	add_action("do_shows","shows");
}

int do_gocook()
{
	this_player()->move("/d/gaibang/zhulin3");
	write("���Ѿ�����ؤ�����˵ĵط��ˡ�\n");
	return 1;
}

int do_shows(string arg)
{
	if(!arg) return notify_fail("��Ҫ��ʲô��ʽ���������ܣ�(cbc/zdf/hqt/nrt/jhj)\n");

	if(arg=="���ײ�" || arg=="cbc")
		write("
                          "HIW"���ײ�"NOR"

    Խ��ƽ����ʽ��Խ���湦����ԭ�ϰײˡ����͡�Ѽ�ƣ�ȡ���Ķ���
Ҷ����ȡѼ��ĩ���ͣ������֮��������壬��ζ���

    �ײˣ����ݳ��Ϲ�Ʒ̯С��������ã����ͣ�ѯ����������¥С��
�ɵã�Ѽ�ƣ�����(cut)��Ѽ�ɵá�\n");

	if(arg=="������" || arg=="zdf")
		write("
                          "HIW"������"NOR"

    �˲�����������������ʵ����������֮�˲������á���ԭ�϶�����
���ȣ��Ƚ������ʿ������˶�ʮ�ĸ�Բ�ף��ٽ��������ɶ�ʮ�ĸ�С��
�ֱ������ڣ���ס�����������ȵ����죬���ȵ���ζ��ȫ���˶���֮
�У�����ȴ��ȥ��ʳ���˲�ζ���ʶ����壬�������ڽ���������С��
�����������������֡����Ϊ�ۡ������������Ի������ʮ��������ҹ����

    ���������ݳ��Ͻֱ߾ƹݿ���ã����ȣ�����¥��¥�ƹ񴦿���á�\n");

	if(arg=="������" || arg=="hqt")
		write("
                          "HIW"������"NOR"

    ������ԭ�Ϻ�Ҷ������ӣ�ң�����⣬���������ӣ��֮��Ƕ��
���֮�⣬��������������Ժ�Ҷ�尾���ɡ��ɲ�ʱ������������ӣ
Ư�����ϣ�����ӳ�����£���Ƭ����ɢ�����ܣ���ɫ��ӳ�����޶�Ŀ֮
������֮���к�Ҷ���㡢���֮�ʡ�ӣ��֮�𣬰��֮��ζ�������
����ζ����ӳ��ɣ�����ʫ����˵�����ع���𣚣�ں�֮�ޣ�����Ů��
���Ӻ��ϡ��������������롣

    ��Ҷ����Ȫ����ͨ�δ�����ã����������ݳǽ������ֿ���(pick)
�ã�ӣ�ң����ݳ��Ϲ�Ʒ̯С��������ã�����⣬���ݳǽ������
�ã��������ݳǽ���ʰ�á�\n");

	if(arg=="ţ����" || arg=="nrt")
		write("
                          "HIW"ţ����"NOR"

    �˲���Ϊ�����˭������÷����ԭ�Ϲ������ֲ�ͬ���࣬�ֱ��ǣ�
Сţ���ӣ�������Σ�С����䣬��⣬���⣻����������������Ϊ
һ��С����������������Ϊ����С�������ٽ�֮����һ��Ϊһ����������
�˰�һһ���ɣ�һͬ�˳�һ����������ֻ���⣬�������ҧ��һ����ζ��
�ţͬ������һ����ζ��������ı仯���ƣ��˲˹��ж�ʮ��䣬����
��÷��֮������������������ӣ������Ϊ�����˭������÷������˼
֮�ɣ�ζ��֮�أ�ʵ��Ѱ��ţ��ɱȣ�

    ţ�⣬�����ܴ����ţ�ɵã����⣬���ԭ��������ɵã�����䣬
����ɽ��С���ݸ�����С��ɵã���⣬���ݳǽ�����ӿɵã����⣬
���ݳǽ���Ұ�ÿɵá�\n");

	if(arg=="�л���" || arg=="jhj")
		write("
                          "HIW"�л���"NOR"
    ����֮�У��˲�ԭ�����٣�������ȴ��Ϊ���ѣ��������ڻ������
���ղ��������ۻ��ϣ���ζ�����ͬ����ԭ�Ϲ�����ʪ�࣬�����佣
���ʼ�ϴ��֮�á����ʿ�(cut)������ϴȥ(xi)���࣬����(guo)ʪ�࣬
������֮(kao)������Ʈ��֮ʱ���ٿ�ʮ���뼴ȡ������(bo)���࣬��
ë������䣬����������ۣ�Ũ���˱ǡ��˲˷��ɡ�

    ��������ɽ�����ϴ�������Я�У�ʪ�࣬���ں�����������ȡ��\n");

	if(arg=="���ײ�" || arg=="cbc" || arg=="������" || arg=="zdf" || arg=="������" || arg=="hqt" || arg=="ţ����" || arg=="nrt" || arg=="�л���" || arg=="jhj")
	{
		write("
*******************************************************************
���˽л�������ʱ�տ�֮�⣬��Ĳ�ʽҪ����
����С�� -��������ؤ�����Ϊ���ݳ��ڵİ��г������ղ������ĵط�����
���ʹ�� cook ���ײ�/������/ţ����/������ ָ�������ˡ�Ҫ��fire��\n");
	if(wizardp(this_player())) write("��ʦ������ cooks ָ�ֱ�ӻ�����˵�ԭ�ϡ���gocookָ��ֱ�ӵ������˴���\n");
		write("*******************************************************************\n");
		message_vision(CYN"$N���������ϸ�ؿ��š�\n"NOR,this_player());
	}
	else write("��Ҫ��ʲô��ʽ���������ܣ�(cbc/zdf/hqt/nrt/jhj)\n");
	return 1;
}

int do_cooks(string arg)
{
	object me,fire,cook_needs;

	me=this_player();

	if(!arg) return notify_fail("��Ҫʲô�˵�ԭ�ϣ�(cbc/zdf/hqt/nrt/jhj)\n");

	if(!present("huozhe",me))
	{
		fire=new("/d/xingxiu/npc/obj/fire");
		if(!fire) write("����"+zzz+"\n");
		else fire->move(me);
	}

	if(arg=="���ײ�" || arg=="cbc")
	{
		write("���ײˣ���Ҫ  �ײˣ����ͣ�Ѽ�ơ�\n");

/*****************************************
 �ײˣ�/clone/food/baicai.c   "baicai"  
 ���ͣ�/clone/food/jiyou.c    "ji you"
 Ѽ�ƣ�/clone/food/yazhang.c  "ya zhang"
******************************************/

		if(!present("baicai",me))  // ��ײ�
		{
			cook_needs=new("/clone/food/baicai");
			if(!cook_needs) write("�ײ�"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"�ײ��ˡ�\n");

		if(!present("ji you",me))  // �伦��
		{
			cook_needs=new("/clone/food/jiyou");
			if(!cook_needs) write("����"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"�����ˡ�\n");

		if(!present("ya zhang",me))  // ��Ѽ��
		{
			cook_needs=new("/clone/food/yazhang");
			if(!cook_needs) write("Ѽ��"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"Ѽ���ˡ�\n");

		write("ok.\n");
		return 1;
	}

	if(arg=="������" || arg=="zdf")
	{
		write("����������Ҫ ���������ȡ�\n");

/**************************************
 ������/clone/food/tofu.c   "doufu"
 ���ȣ�/clone/food/ham.c    "huo tui"
**************************************/

		if(!present("doufu",me))  // �䶹��
		{
			cook_needs=new("/clone/food/tofu");
			if(!cook_needs) write("����"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"�����ˡ�\n");

		if(!present("huo tui",me))  // �����
		{
			cook_needs=new("/clone/food/ham");
			if(!cook_needs) write("����"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"�����ˡ�\n");

		write("ok.\n");
		return 1;
	}

	if(arg=="������" || arg=="hqt")
	{
		write("����������Ҫ ��Ҷ������ӣ�ң�����⣬����\n");

/*******************************************************
 ��Ҷ��  /d/dongtinghu/obj/heye.c        "he ye"
 ����  /d/gaibang/obj/zhusun.c         "zhu sun"
 ӣ�ң�  /d/city/npc/obj/cherry.c        "ying tao"
 ����⣺/clone/beast/obj/banjiu-rou.c   "banjiu rou"
 ����    /d/emei/obj/flower.c            "flower"
*******************************************************/

		if(!present("he ye",me))  // ���Ҷ
		{
			cook_needs=new("/d/dongtinghu/obj/heye");
			if(!cook_needs) write("��Ҷ"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"��Ҷ�ˡ�\n");

		if(!present("zhu sun",me))  // ������
		{
			cook_needs=new("/d/gaibang/obj/zhusun");
			if(!cook_needs) write("����"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"�����ˡ�\n");

		if(!present("ying tao",me))  // ��ӣ��
		{
			cook_needs=new("/d/city/npc/obj/cherry");
			if(!cook_needs) write("ӣ��"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"ӣ���ˡ�\n");

		if(!present("banjiu rou",me))  // ������
		{
			cook_needs=new("/clone/beast/obj/banjiu-rou");
			if(!cook_needs) write("�����"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"������ˡ�\n");

		if(!present("flower",me))  // �仨
		{
			cook_needs=new("/d/emei/obj/flower");
			if(!cook_needs) write("��"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"���ˡ�\n");

		write("ok.\n");
		return 1;
	}

	if(arg=="ţ����" || arg=="nrt")
	{
		write("ţ��������Ҫ ţ�⣬���⣬����䣬��⣬���⡣\n");

/*************************************************
 ţ�⣺  /d/heimuya/obj/niurou.c      "niu rou"
 ���⣺  /clone/beast/obj/yangrou2.c  "yang rou"
 ����䣺/clone/beast/obj/pork.c      "zhu erduo"
 ��⣺  /d/gaibang/obj/zhangrou.c    "zhang rou"
 ���⣺  /d/wudang/npc/turou.c        "tu rou"
**************************************************/

		if(!present("niu rou",me))  // ��ţ��
		{
			cook_needs=new("/d/heimuya/obj/niurou");
			if(!cook_needs) write("ţ��"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"ţ���ˡ�\n");

		if(!present("yang rou",me))  // ������
		{
			cook_needs=new("/clone/beast/obj/yangrou2");
			if(!cook_needs) write("����"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"�����ˡ�\n");

		if(!present("zhu erduo",me))  // �������
		{
			cook_needs=new("/clone/beast/obj/pork");
			if(!cook_needs) write("�����"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"������ˡ�\n");

		if(!present("zhang rou",me))  // �����
		{
			cook_needs=new("/d/gaibang/obj/zhangrou");
			if(!cook_needs) write("���"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"����ˡ�\n");

		if(!present("tu rou",me))  // ������
		{
			cook_needs=new("/d/wudang/npc/turou");
			if(!cook_needs) write("����"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"�����ˡ�\n");

		write("ok.\n");
		return 1;
	}

	if(arg=="�л���" || arg=="jhj")
	{
		write("�л�������Ҫ ������װ���˽��ʹ������������ࡣ�����������뿴shows jhj.\n");

/********************************************
 ������ /d/gaibang/obj/gongji.c  "gong ji"
 ʪ�ࣺ /d/gaibang/obj/mud.c     "mud"
********************************************/

		if(!present("gong ji",me))  // �乫��
		{
			cook_needs=new("/d/gaibang/obj/gongji");
			if(!cook_needs) write("����"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"�����ˡ�\n");

		if(!present("mud",me))  // ��ʪ��
		{
			cook_needs=new("/d/gaibang/obj/mud");
			if(!cook_needs) write("ʪ��"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"ʪ���ˡ�\n");

		write("ok.\n");
		return 1;
	}

	write("û����ζ�˿�����(cbc/zdf/hqt/nrt/jhj)\n");
	return 1;
}
