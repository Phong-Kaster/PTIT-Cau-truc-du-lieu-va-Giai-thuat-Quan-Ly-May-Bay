#pragma once

struct ticket
{
	unsigned int CMND;
	int Status;
	/* CHU THICH
	CMND = so CCCD cua Hanh khach
	Status = so ve cua Hanh khach */
};
typedef struct ticket Ticket;