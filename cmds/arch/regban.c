// Code of ShenZhou
// regban.c
// Created by Dts@XKX, 1997-04-15
// cf ban.c

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
		REGBAN_D->print();
	else if (sscanf(arg, "+ %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("���ܽ��� *, +, ? ��β�ĵ�ַ��\n");
		else
			REGBAN_D->add(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
		REGBAN_D->remove(site);
	else if (sscanf(arg, "? %s", site) == 1)
		REGBAN_D->check(site);
	else write("ָ���ʽ��regban [+|-|? hostname|user@hostname]\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
ָ���ʽ��regban [+|-|? hostname_pettern|user@hostname_pattern]

��ֹ����ע���µ�����Է��������⵷�ҡ�
���� regban + smart@.*hacker.com
     regban - smart@.*hacker.com
     regban ? smart@attack.hacker.com
���� regban + hacker.com
     regban - hacker.com
     regban ? attack.hacker.com
HELP
	);
	return 1;
}
