// gumu-xinfa.c ��Ĺ�ɳ����ķ�--��Ů�ľ�����֮һ
// by April 01/08/06

#include <combat.h>

inherit FORCE;

string check() { return "force"; }

#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// ����ѧ
{
	return notify_fail("��������ѧϰ�ɣ�����������ϰ��Ů�ľ���\n");
}

int practice_skill(object me)
// ������
{
	return notify_fail("�𼱣���������Ů�ľ����������ġ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunu-xinjing/" + func;
}