// ֵǮ��Ư����ʯ�����ؿ������á�gem_md.c
// by naihe �κ�  2002-05-16

#include <ansi.h>
inherit ITEM;

string clname;
int temp,tempa,tempb,
temp=(random(50000)+30000),
tempa=(temp*(random(5)+1)),
tempb=(temp/(random(5)+1));

int color=(random(5));
// ����ĸ��ء���ɫ���Լ���ֵ��

void create()
{
	if(color==0)
	{
		set_name(HIG"�̱�ʯ"NOR, ({"gem","baoshi","green gem"}));
		clname="��";
	}

	if(color==1)
	{
		set_name(HIR"�챦ʯ"NOR, ({"gem","baoshi","red gem"}));
		clname="��";
	}

	if(color==2)
	{
		set_name(HIB"����ʯ"NOR, ({"gem","baoshi","blue gem"}));
		clname="��";
	}

	if(color==3)
	{
		set_name(HIM"�ϱ�ʯ"NOR, ({"gem","baoshi","violet gem"}));
		clname="��";
	}

	if(color==4)
	{
		set_name(HIC"������ʯ"NOR, ({"gem","baoshi","sapphire gem"}));
		clname="����";
	}

	switch(random(5))
	{
		case 0:set("long","һ��"+clname+"ɫ�ı�ʯ���������˵Ĺ�â��\n");
		break;

		case 1:set("long","��ű�ʯɫ����������"+clname+"����ȫ��"+clname+"�����˰������֡�\n");
		break;

		case 2:set("long","��ʯ�����ĵ�ɢ����"+clname+"ɫ�Ĺ�â��\n");
		break;

		case 3:set("long","��ʯ��ɢ����"+clname+"ɫ�Ĺ�â��ӳ������������������������˼��\n");
		break;

		case 4:set("long","��ʯ�ﵭ����ɢ����"+clname+"ɫ�Ĺ�â��\n");
		break;

	}

	set_weight(tempb);
	set("unit", "��");
	set("value",tempa);

//	set("long","��ֵ�ǣ�"+tempa+", ������"+tempb+".\n"); ��仰������ʱ�á�
	setup();
}
